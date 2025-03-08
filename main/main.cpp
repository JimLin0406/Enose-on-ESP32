#include <stdio.h>
#include "driver/i2c_master.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


#include "esp_log.h"
#include "esp_lcd_gc9a01.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "esp_timer.h"
#include "lvgl.h"
#include "driver/ledc.h"

#include "i2c_device.h"     // self-defined i2c_device.h
#include "mylvgl.h"         // self-defined i2c_device.h
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


lv_ui guider_ui;

SemaphoreHandle_t touch_mux = NULL; 

QueueHandle_t dataQueue;

i2c_device_t device_HS4011, device_BME280, device_PCA9547, device_Enose;

void i2c_read_task(void *arg){

    HS4011_DATA hs4011_data;
    BME280_DATA compensated_pressure_data;
    MEMS_DATA resistants_data;
    SensorData_t sensor_data;

    while (true) {
        if (read_from_HS4011(&device_HS4011,&hs4011_data) == ESP_OK){
            uint16_t humidity = (((hs4011_data.data[0] << 8) | hs4011_data.data[1]) * 100) >> 14;
            uint16_t temperature = ((((hs4011_data.data[2] << 8) | hs4011_data.data[3]) * 165) >> 14) - 40;
            uint8_t calculatedCRC = CRC8(hs4011_data.data, 4);
            if (calculatedCRC == hs4011_data.crc){
                sensor_data.humidity = humidity;
                sensor_data.temperature = temperature;
            }
            else{
                ESP_LOGE("MAIN TAG", "CRC Check: FAIL");
            }
        }

        if (read_from_BME280(&device_BME280,&compensated_pressure_data) == ESP_OK){
            sensor_data.pressure = (float) compensated_pressure_data/25600.0;
        }

        if (read_from_MEMS(&device_PCA9547,&device_Enose,&resistants_data) == ESP_OK){
            for (int i = 0; i < 8; i++) {
                sensor_data.resistance[i] = *((uint16_t*)(&resistants_data.ch1) + i);
            }
        }
        
        if (xQueueSend(dataQueue, &sensor_data, portMAX_DELAY) != pdPASS) {
            ESP_LOGE("MAIN", "Failed to send data to queue");
        }
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}


void data_read_task(void *arg){
    SensorData_t sensor_data;
    while (true) {
        if (xQueueReceive(dataQueue,&sensor_data,portMAX_DELAY) == pdTRUE){
            update_channels_on_screen(&guider_ui, &sensor_data);


            // printf("Humidity: %d\nTemperature: %d\nPressure: %.2f\n", 
            //     sensor_data.humidity, sensor_data.temperature, sensor_data.pressure);
            // for (int i=0;i<8;i++){
            //     printf("ch %d: %d\n",i+1, sensor_data.resistance[i]);
            // }
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}


void UI_task(void *arg){
    setup_ui(&guider_ui);
    events_init(&guider_ui);
    // lv_init_keyboard(&guider_ui);
    
    while (true)
    {
        /* code */
        lv_timer_handler();
        vTaskDelay(10/portTICK_PERIOD_MS);
    }

}

extern "C" void app_main(void){   
    // Initial I2C master bus
    i2c_master_bus_config_t i2c_mst_config = {
        .i2c_port = -1,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
    };
    i2c_master_bus_handle_t bus_handle;
    ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_mst_config, &bus_handle));

    // Init all I2C slaves
    
    ESP_ERROR_CHECK(i2c_device_init(&device_HS4011, bus_handle, HS4011_ADDR));
    ESP_ERROR_CHECK(i2c_device_init(&device_BME280, bus_handle, BME280_ADDR));
    ESP_ERROR_CHECK(i2c_device_init(&device_PCA9547, bus_handle, PCA9547_ADDR));
    ESP_ERROR_CHECK(i2c_device_init(&device_Enose, bus_handle, MEMS_ADDR));

    // Setting measurement parameter of each slave
    if (set_BME280_mode(&device_BME280) != ESP_OK){
        printf("GG");
    }

    // install gc9a01 driver and init lvgl displayer
    init_gc9a01();

    // install cst816s dirver and set connection to lvgl in that interacting with touch-screen
    touch_mux = xSemaphoreCreateBinary();
    init_cst816s();
    
    
    dataQueue = xQueueCreate(1, sizeof(SensorData_t));
    if (dataQueue == NULL) {
        ESP_LOGE("APP", "Failed to create queue");
        return;
    }
    
    xTaskCreatePinnedToCore(i2c_read_task, "I2C_Read_Task", 2048, nullptr, 2, NULL,1);
    vTaskDelay(pdMS_TO_TICKS(1000));
    xTaskCreatePinnedToCore(UI_task, "UI_Task", 4096, nullptr, 1, NULL,0);
    vTaskDelay(pdMS_TO_TICKS(1000));
    xTaskCreatePinnedToCore(data_read_task, "Data_print_Task", 2048, nullptr, 2, NULL,1);

}
