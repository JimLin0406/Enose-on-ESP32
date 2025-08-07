#include <stdio.h>
#include "driver/i2c_master.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_lcd_st7796.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "esp_timer.h"
#include "lvgl.h"
#include "driver/ledc.h"
#include "esp_spiffs.h"
#include "dl_model_base.hpp"
#include "esp_task_wdt.h"
#include "driver/gpio.h"

#include "i2c_device.h"     // self-defined i2c_device.h
#include "mylvgl.h"         // self-defined i2c_device.h
#include "sdmmc.h"         // self-defined sdmmc.h
#include "dl_model.hpp"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include <dirent.h>

#include "diskio_impl.h"
#include "diskio_sdmmc.h"
#include "tusb_msc_storage.h"
#include "tinyusb.h"

#define GPIO_ENABLE_PUMP    GPIO_NUM_2
#define GPIO_ENABLE_VALVE   GPIO_NUM_1
#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<1) | (1ULL<<2))

static SemaphoreHandle_t i2c_mutex;
volatile bool host_disconnected;

lv_ui guider_ui;
Enose_STATE Enose_state = IDLE_state;
SemaphoreHandle_t touch_mux = NULL; 
QueueHandle_t dataQueue, ui_msg_queue;
i2c_device_t device_HS4011, device_BME280, device_PCA9547, device_Enose;
TaskHandle_t start_measurement_task_handle= NULL;
TaskHandle_t whole_measurement_task_handle = NULL;
TaskHandle_t classification_task_handle = NULL;
TimerHandle_t measurement_timer;
dl::Model *model = nullptr;

char duration_prep[8];
char duration_measure[8];
char duration_clean[8];

SensorData_t sensor_data_onCore0;

void i2c_read_task(void *arg){

    HS4011_DATA hs4011_data;
    BME280_DATA compensated_pressure_data;
    MEMS_DATA resistants_data;
    printf("Thread: i2c_read_task\n");

    while (true) {
        if (read_from_HS4011(&device_HS4011,&hs4011_data) == ESP_OK){
            uint16_t humidity = (((hs4011_data.data[0] << 8) | hs4011_data.data[1]) * 100) >> 14;
            uint16_t temperature = ((((hs4011_data.data[2] << 8) | hs4011_data.data[3]) * 165) >> 14) - 40;
            uint8_t calculatedCRC = CRC8(hs4011_data.data, 4);
            if (calculatedCRC == hs4011_data.crc){
                sensor_data_onCore0.humidity = humidity;
                sensor_data_onCore0.temperature = temperature;
                // printf("Humidity: %d\n",sensor_data_onCore0.humidity);
                // printf("Temperature: %d\n",sensor_data_onCore0.temperature);
            }
            else{
                ESP_LOGE("MAIN TAG", "CRC Check: FAIL");
            }
        }

        if (read_from_BME280(&device_BME280,&compensated_pressure_data) == ESP_OK){
            sensor_data_onCore0.pressure = (float) compensated_pressure_data/25600.0;
            // printf("Pressure: %f\n",sensor_data_onCore0.pressure);
        }
        if (xSemaphoreTake(i2c_mutex, portMAX_DELAY)){
            if (read_from_MEMS(&device_PCA9547,&device_Enose,&resistants_data) == ESP_OK){
                for (int i = 0; i < 8; i++) {
                    sensor_data_onCore0.resistance[i] = *((uint32_t*)(&resistants_data.ch1) + i);
                    // printf("ch%d: %ld\n",i+1,sensor_data_onCore0.resistance[i]);
                }
            }
            xSemaphoreGive(i2c_mutex);
        }
        
        if (xQueueSend(dataQueue, &sensor_data_onCore0, portMAX_DELAY) != pdPASS) {
            ESP_LOGE("MAIN", "Failed to send data to queue");
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void update_sensor_data_task(void *arg){
    // Prepare the sensor data for updating UI on UI_task task
    SensorData_t sensor_data;
    while (true) {
        if (xQueueReceive(dataQueue,&sensor_data,portMAX_DELAY) == pdTRUE){
            update_channels_on_screen(&guider_ui, &sensor_data);
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void UI_task(void *arg){
    setup_ui(&guider_ui);
    events_init(&guider_ui);
    lv_init_keyboard(&guider_ui);
    while (true) {
        // char *msg; 
        // if (xQueueReceive(ui_msg_queue, &msg, 0) == pdTRUE) {
        //     lv_msgbox(msg); // Pop-up message window
        // } 

        lv_timer_handler();
        vTaskDelay(10/portTICK_PERIOD_MS);
    }
}

char FILEPATH[32];

void start_measurement_task(void *arg) {
    printf("Thread: start_measurement_task\n");
    while (1){
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY); // receive GIVE singal from start button in events_init.c

        const char *sample_name = lv_textarea_get_text(guider_ui.screen_SettingPage_ta_sampleText);
        if (sample_name == NULL || sample_name[0] == '\0') {
            char *msg = "Please input sample name!";
            xQueueSend(ui_msg_queue, &msg, portMAX_DELAY);
        } 
        else {
            snprintf(FILEPATH, sizeof(FILEPATH), "/sd_card/USB Drive/%s.csv", sample_name);
            if (file_exists(FILEPATH)){
                char *msg = "The filename alreadly exist!";
                xQueueSend(ui_msg_queue, &msg, portMAX_DELAY);
            }
            else {
                printf("File:\"%s.csv\" Start Collection!\n",FILEPATH);
                if (Enose_state==IDLE_state){
                    create_csv_file(FILEPATH);
                    Enose_state = PREPARE_state;
                    gpio_set_level(GPIO_ENABLE_PUMP, 0);
                    gpio_set_level(GPIO_ENABLE_VALVE, 1);

                    xTaskNotifyGive(whole_measurement_task_handle);
                }
                else{
                    printf("Already Collection!\n");
                    char *msg = "Already in measurement!";
                    xQueueSend(ui_msg_queue, &msg, portMAX_DELAY);
                }
            }
        }
    }
}

const char *Enose_state_str[] = {
    "IDLE",
    "PREPARE",
    "MEASURE",
    "CLEAN"
};

int elapsed_count; 

void measurement_timer_callback(TimerHandle_t xTimer) {
    if (elapsed_count==0){
        printf("Collecting data...\n");
        // Get setting parameters
        lv_dropdown_get_selected_str(guider_ui.screen_SettingPage_ddlist_PrepDuration, duration_prep, sizeof(duration_prep));
        lv_dropdown_get_selected_str(guider_ui.screen_SettingPage_ddlist_MeasDuration, duration_measure, sizeof(duration_measure));
        lv_dropdown_get_selected_str(guider_ui.screen_SettingPage_ddlist_CleanDuration, duration_clean, sizeof(duration_clean));
    }
    if (elapsed_count==atoi(duration_prep)){
        Enose_state = MEASURE_state;
        gpio_set_level(GPIO_ENABLE_PUMP, 0);
        gpio_set_level(GPIO_ENABLE_VALVE, 0);
    }
    else if (elapsed_count==(atoi(duration_prep)+atoi(duration_measure))){
        Enose_state = CLEAN_state;
        gpio_set_level(GPIO_ENABLE_PUMP, 0);
        gpio_set_level(GPIO_ENABLE_VALVE, 1);
    }
    else if (elapsed_count==(atoi(duration_prep)+atoi(duration_measure)+atoi(duration_clean))){
        Enose_state = IDLE_state;
        gpio_set_level(GPIO_ENABLE_PUMP, 1);
        gpio_set_level(GPIO_ENABLE_VALVE, 1);
        xTimerStop(measurement_timer, 0);
        return;
    }


    write_csv_data(elapsed_count+1, Enose_state_str[Enose_state], sensor_data_onCore0, FILEPATH);

    elapsed_count++;
}


void whole_measurement_task(void *arg) { // Core:0
    printf("Thread: whole_measurement_task\n");
    measurement_timer = xTimerCreate("MeasurementTimer", pdMS_TO_TICKS(1000), pdTRUE, (void *)0, measurement_timer_callback);
    while (1){
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY); 
        elapsed_count = 0;
        // 每一秒收案一次
        if (measurement_timer != NULL) {
            xTimerStart(measurement_timer, 0);
            lv_label_set_text(guider_ui.screen_SettingPage_btn_start_label, "Measuring");
            lv_obj_set_style_bg_color(guider_ui.screen_SettingPage_btn_start, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
        }
        vTaskDelay(10 / portTICK_PERIOD_MS);
        while (xTimerIsTimerActive(measurement_timer)){
            // 在這加入每500ms 讓lv_bar_create得背景顏色重複閃爍 (trigger by UI_task on core:0)
            if (Enose_state==PREPARE_state) {

                lv_label_set_text(guider_ui.screen_MeasurePage_label_state, "PREPARE STATE");
                lv_obj_set_style_bg_color(guider_ui.screen_MeasurePage_bar_state, lv_color_hex(0x46a3ff), LV_PART_INDICATOR);
                vTaskDelay(500 / portTICK_PERIOD_MS);
                lv_obj_set_style_bg_color(guider_ui.screen_MeasurePage_bar_state, lv_color_hex(0x0a1414), LV_PART_INDICATOR);
                vTaskDelay(500 / portTICK_PERIOD_MS);
            }
            else if (Enose_state==MEASURE_state) {
                lv_label_set_text(guider_ui.screen_MeasurePage_label_state, "MEASURE STATE");
                lv_obj_set_style_bg_color(guider_ui.screen_MeasurePage_bar_state, lv_color_hex(0xff0000), LV_PART_INDICATOR);
                vTaskDelay(500 / portTICK_PERIOD_MS);
                lv_obj_set_style_bg_color(guider_ui.screen_MeasurePage_bar_state, lv_color_hex(0x0a1414), LV_PART_INDICATOR);
                vTaskDelay(500 / portTICK_PERIOD_MS);
            }
            else if (Enose_state==CLEAN_state) {
                lv_label_set_text(guider_ui.screen_MeasurePage_label_state, "CLEAN STATE");
                lv_obj_set_style_bg_color(guider_ui.screen_MeasurePage_bar_state, lv_color_hex(0xff5809), LV_PART_INDICATOR);
                vTaskDelay(500 / portTICK_PERIOD_MS);
                lv_obj_set_style_bg_color(guider_ui.screen_MeasurePage_bar_state, lv_color_hex(0x0a1414), LV_PART_INDICATOR);
                vTaskDelay(500 / portTICK_PERIOD_MS);
            }
        }
        lv_label_set_text(guider_ui.screen_MeasurePage_label_state, "IDLE STATE");
        lv_obj_set_style_bg_color(guider_ui.screen_MeasurePage_bar_state, lv_color_hex(0x0dff00), LV_PART_INDICATOR);
        lv_label_set_text(guider_ui.screen_SettingPage_btn_start_label, "Start");
        lv_obj_set_style_bg_color(guider_ui.screen_SettingPage_btn_start, lv_color_hex(0x0071ff), LV_PART_MAIN|LV_STATE_DEFAULT);
        printf("Measurement finished.\n");
    }
}

void classification_task(void *arg) {
    printf("Thread: classification_task\n");
    while (1){
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY); 

        char file_name[32];
        lv_dropdown_get_selected_str(guider_ui.screen_AnalysisPage_ddlist_file_in_SPIFFS, file_name, sizeof(file_name));
        
        char file_path[64];
        snprintf(file_path, sizeof(file_path), "/saved_data/%s", file_name);
        FILE* f = fopen(file_path, "r");
        if (f == NULL)
            printf("Failed to open file: %s\n", file_path);
        else
            printf("sucess to open file: %s\n", file_path);
        
        enose_data sensor_data;
        sensor_data.read_csv_file(f);

        fclose(f);
    
        std::vector<int> prep_indices = sensor_data.get_STEP_indices({"Prep"});
    
        std::vector<double> mean_values = sensor_data.calculate_mean_for_channels(prep_indices);
    
        // std::cout << "Mean values for channels (ch1 to ch16) for 'Prep':" << std::endl;
        // for (int i = 0; i < mean_values.size(); ++i) {
        //     std::cout << "ch" << (i + 1) << ": " << mean_values[i] << std::endl;
        // }
    
        std::vector<int> measure_indices = sensor_data.get_STEP_indices({"Measure","Clean"});
    
        std::vector<std::vector<int>> measure_data = sensor_data.get_baseline_removal_data(measure_indices,70);
        // std::cout<<"measure_data:"<<std::endl;
        // print_V_Vector_data(measure_data,5);
    
        std::vector<std::vector<double>> good_data = subtract_mean_from_measure(measure_data,mean_values);
    
        float* data = normalize_and_convert_to_float_array(good_data);
        std::cout<<"Normalized Data:"<<std::endl;
        // for (int i=0;i<70;i++){
        //     for (int j=0;j<16;j++){
        //         std::cout<<data[i*16+j]<<" ";
        //     }
        //     std::cout<<""<<std::endl;
        // }
        
        std::map<std::string, TensorBase *> graph_test_inputs = generate_inputs(data); // Long time calculation

        printf("Load feature model.....\n");
        Model *model = nullptr;
        model = new Model("model", fbs::MODEL_LOCATION_IN_FLASH_PARTITION);
        model->run(graph_test_inputs);
        
        std::map<std::string, TensorBase *> output = model->get_outputs();

        
        std::cout<<"output_gram:"<<std::endl;
        int max_value = INT8_MIN; 
        int max_index = -1; 
        for (int i = 0; i < output["output_gram"]->size; i++) {
            int current_value = output["output_gram"]->get_element<int8_t>(i);
            printf("%d, ", output["output_gram"]->get_element<int8_t>(i));
            if (current_value > max_value) {
                max_value = current_value;
                max_index = i;
            }
        }
        printf("\n");
        lv_label_set_text(guider_ui.screen_AnalysisPage_label_predicted_Gram, gram_names[max_index]);
        vTaskDelay(pdMS_TO_TICKS(100));


        std::cout<<"output_class:"<<std::endl;
        max_value = INT8_MIN; 
        max_index = -1; 
        for (int i = 0; i < output["output_class"]->size; i++) {
            int current_value = output["output_class"]->get_element<int8_t>(i);
            printf("%d, ", output["output_class"]->get_element<int8_t>(i));
            if (current_value > max_value) {
                max_value = current_value;
                max_index = i;
            }
        }
        printf("\n");
        lv_label_set_text(guider_ui.screen_AnalysisPage_label_predicted_species, bacteria_names[max_index]);
        vTaskDelay(pdMS_TO_TICKS(100));

        std::cout<<"output_concen:"<<std::endl;
        for (int i = 0; i < output["output_concen"]->size; i++) {
            printf("%d, ", output["output_concen"]->get_element<int8_t>(i));
        }
        printf("\n");

        int8_t value = output["output_concen"]->get_element<int8_t>(0);
        int8_t exponent = output["output_concen"]->exponent;
        char value_str[10];
        if (exponent!=0) snprintf(value_str,sizeof(value_str),"%.2f",(float)value * pow(2, exponent));
        else snprintf(value_str,sizeof(value_str),"%d",value);

        lv_label_set_text(guider_ui.screen_AnalysisPage_label_predicted_concentrations, value_str);
        vTaskDelay(pdMS_TO_TICKS(100));


        delete model;
        printf("Delete classifier model.....\n");
        
    }
}


void whole_classification_task(void *arg) {
    printf("Thread: whole_classification_task\n");
    while (1){
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        printf("Load feature model.....\n");
        Model *model = nullptr;
        model = new Model("model", fbs::MODEL_LOCATION_IN_FLASH_PARTITION);
        

        DIR *dir = opendir("/saved_data");
        if (!dir) {
            ESP_LOGE("SPIFFS", "Failed to open directory");
            return;
        }
        struct dirent *entry;
        int idx_file = 1;
        while ((entry = readdir(dir)) != NULL) {
            printf("\n%d\n",idx_file++);
            char file_name[32];
            char file_path[64];
            strncpy(file_name, entry->d_name, sizeof(file_name) - 1);

            snprintf(file_path, sizeof(file_path), "/saved_data/%s", file_name);
            FILE* f = fopen(file_path, "r");
            if (f == NULL)
                printf("Failed to open file:  %s\n", file_path);
            else
                printf("Sucess to open file:  %s\n", file_path);
            enose_data sensor_data;
            sensor_data.read_csv_file(f);
            fclose(f);

            std::vector<int> prep_indices = sensor_data.get_STEP_indices({"Prep"});
            std::vector<double> mean_values = sensor_data.calculate_mean_for_channels(prep_indices);
            std::vector<int> measure_indices = sensor_data.get_STEP_indices({"Measure","Clean"});
            std::vector<std::vector<int>> measure_data = sensor_data.get_baseline_removal_data(measure_indices,70);
            std::vector<std::vector<double>> good_data = subtract_mean_from_measure(measure_data,mean_values);

            float* data = normalize_and_convert_to_float_array(good_data);
            
            std::map<std::string, TensorBase *> graph_test_inputs = generate_inputs(data); // Long time calculation
            
            int64_t start_time = esp_timer_get_time();
            model->run(graph_test_inputs);
            int64_t end_time = esp_timer_get_time()-start_time;
        
            std::map<std::string, TensorBase *> output = model->get_outputs();

            // std::cout<<"output_gram:"<<std::endl;
            int max_value = INT8_MIN; 
            int max_index = -1; 
            for (int i = 0; i < output["output_gram"]->size; i++) {
                int current_value = output["output_gram"]->get_element<int8_t>(i);
                // printf("%d, ", output["output_gram"]->get_element<int8_t>(i));
                if (current_value > max_value) {
                    max_value = current_value;
                    max_index = i;
                }
            }
            printf("Predict Gram: %s\n",gram_names[max_index]);
            vTaskDelay(pdMS_TO_TICKS(100));

            // std::cout<<"output_class:"<<std::endl;
            max_value = INT8_MIN; 
            max_index = -1; 
            for (int i = 0; i < output["output_class"]->size; i++) {
                int current_value = output["output_class"]->get_element<int8_t>(i);
                // printf("%d, ", output["output_class"]->get_element<int8_t>(i));
                if (current_value > max_value) {
                    max_value = current_value;
                    max_index = i;
                }
            }
            printf("Predict Species: %s\n",bacteria_names[max_index]);
            vTaskDelay(pdMS_TO_TICKS(100));

            // std::cout<<"output_concen:"<<std::endl;
            max_value = INT8_MIN; 
            max_index = -1; 
            for (int i = 0; i < output["output_concen"]->size; i++) {
                int current_value = output["output_concen"]->get_element<int8_t>(i);
                // printf("%d, ", output["output_concen"]->get_element<int8_t>(i));
                if (current_value > max_value) {
                    max_value = current_value;
                    max_index = i;
                }
            }
            printf("Predict Concentration: %s\n",concentration_names[max_index]);
            vTaskDelay(pdMS_TO_TICKS(100));
            printf("Duration: %lld\n",end_time);  // 單位 us

        }
        closedir(dir);
    }
}

extern "C" void app_main(void){  

    i2c_mutex = xSemaphoreCreateMutex();

    printf("Total Free Heap: %lu bytes\n", esp_get_free_heap_size());
    vTaskDelay(pdMS_TO_TICKS(2000)); 

    // Setup GPIO
    gpio_config_t io_conf = {
        .pin_bit_mask = GPIO_OUTPUT_PIN_SEL,
        .mode = GPIO_MODE_OUTPUT,               
        .pull_up_en = GPIO_PULLUP_DISABLE,       
        .pull_down_en = GPIO_PULLDOWN_DISABLE,   
        .intr_type = GPIO_INTR_DISABLE
    };
    ESP_ERROR_CHECK(gpio_config(&io_conf));
    gpio_set_level(GPIO_ENABLE_PUMP, 1);
    gpio_set_level(GPIO_ENABLE_VALVE, 1);

    // Initial I2C master bus
    i2c_master_bus_config_t i2c_mst_config = {
        .i2c_port = -1,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 10,
        .flags = {
            .enable_internal_pullup = true,
        },
    };
    i2c_master_bus_handle_t bus_handle;
    ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_mst_config, &bus_handle));
    gpio_set_drive_capability(I2C_MASTER_SDA_IO, GPIO_DRIVE_CAP_3);
    gpio_set_drive_capability(I2C_MASTER_SCL_IO, GPIO_DRIVE_CAP_3);
    vTaskDelay(pdMS_TO_TICKS(200)); 

    // Init all I2C slaves
    ESP_ERROR_CHECK(i2c_device_init(&device_HS4011, bus_handle, HS4011_ADDR));
    ESP_ERROR_CHECK(i2c_device_init(&device_BME280, bus_handle, BME280_ADDR));
    ESP_ERROR_CHECK(i2c_device_init(&device_PCA9547, bus_handle, PCA9547_ADDR));
    ESP_ERROR_CHECK(i2c_device_init(&device_Enose, bus_handle, MEMS_ADDR));

    // Setting measurement parameter of each slave
    ESP_ERROR_CHECK(set_BME280_mode(&device_BME280));
    ESP_ERROR_CHECK(set_HS4011_mode(&device_HS4011));


    // install st7796 driver and init lvgl displayer
    init_st7796();

    // install ft6336u dirver and set connection to lvgl in that interacting with touch-screen
    touch_mux = xSemaphoreCreateBinary();
    init_ft6336u();
    
    dataQueue = xQueueCreate(1, sizeof(SensorData_t));
    ui_msg_queue = xQueueCreate(1, sizeof(char *));     

    //Pin 脚 IO35、IO36、IO37 已连接至模组内部集成的 Octal SPI PSRAM，可用于其他功能

    static sdmmc_card_t *card = NULL;
    ESP_ERROR_CHECK(storage_init_sdmmc(&card));

    const tinyusb_msc_sdmmc_config_t config_sdmmc = {
        .card = card,
        .callback_mount_changed = storage_mount_changed_cb,  /* First way to register the callback. This is while initializing the storage. */
        .callback_premount_changed = nullptr,
        .mount_config = {
            .format_if_mount_failed = false,
            .max_files = 5,
        }
    };


    ESP_ERROR_CHECK(tinyusb_driver_install(&tusb_cfg));
    


    ESP_ERROR_CHECK(tinyusb_msc_storage_init_sdmmc(&config_sdmmc));
    _mount();

    printf("USB MSC initialization DONE\n");


    vTaskDelay(pdMS_TO_TICKS(200)); // Avoid main_task(cpu0) and spiffs_init_task(cpu1) run in the same time
    xTaskCreatePinnedToCore(i2c_read_task, "I2C_Read_Task", 4096, nullptr, 3, NULL,0);
    xTaskCreatePinnedToCore(start_measurement_task, "Start_Measurement_Task", 3072, nullptr, 2, &start_measurement_task_handle,0);
    xTaskCreatePinnedToCore(whole_measurement_task, "Whole_Measurement_Task", 3072, nullptr, 2, &whole_measurement_task_handle,0);
    xTaskCreatePinnedToCore(classification_task, "Classification_Task", 4096, nullptr, 1, &classification_task_handle,0);

    xTaskCreatePinnedToCore(UI_task, "UI_Task", 4096, nullptr, 2, NULL,1);
    xTaskCreatePinnedToCore(update_sensor_data_task, "Updata_Sensor_Task", 3072, nullptr, 1, NULL,1);

    // vTaskDelay(pdMS_TO_TICKS(1000));
}
