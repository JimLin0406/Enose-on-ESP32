#include "mylvgl.h"

extern SemaphoreHandle_t touch_mux;

static const char *TAG = "mylvgl.c";

static bool example_notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx){
    lv_disp_drv_t *disp_driver = (lv_disp_drv_t *)user_ctx;
    lv_disp_flush_ready(disp_driver); // 告訴lv_task_handler調用flush_cb
    return false;
}

static void example_lvgl_flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map){
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t) drv->user_data;
    int offsetx1 = area->x1;
    int offsetx2 = area->x2;
    int offsety1 = area->y1;
    int offsety2 = area->y2;

    // int offsetx1 = area->x1;
    // int offsetx2 = (area->x2 + 1 > LCD_WIDTH) ? LCD_WIDTH : area->x2 + 1;
    // int offsety1 = area->y1;
    // int offsety2 = (area->y2 + 1 > LCD_HEIGHT) ? LCD_HEIGHT : area->y2 + 1;

    // copy a buffer's content to a specific area of the display
    esp_lcd_panel_draw_bitmap(panel_handle, offsetx1, offsety1, offsetx2+1, offsety2+1, color_map);
}

static void example_increase_lvgl_tick(void *arg){
    /* Tell LVGL how many milliseconds has elapsed */
    lv_tick_inc(EXAMPLE_LVGL_TICK_PERIOD_MS);
}

void setup_pwm(int gpio_lcd_pwm) {
    // 設置 LEDC 計時器
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_LOW_SPEED_MODE, // 設定使用的模式
        .duty_resolution = LEDC_TIMER_8_BIT, // 設定解析度 (0-255)
        .timer_num = LEDC_TIMER_0, // 設定計時器
        .freq_hz = 5000, // 設定頻率
        .clk_cfg = LEDC_USE_APB_CLK, // 設定時鐘源
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    // 設置 LEDC 通道
    ledc_channel_config_t ledc_channel = {
        .gpio_num = gpio_lcd_pwm, // 設定引腳
        .speed_mode = LEDC_LOW_SPEED_MODE, // 設定模式
        .channel = LEDC_CHANNEL_0, // 設定通道
        .intr_type = LEDC_INTR_DISABLE, // 禁用中斷
        .timer_sel = LEDC_TIMER_0, // 設定計時器
        .duty = 128, // 初始占空比為 0
        .hpoint = 0, 
    };
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
}

static lv_disp_draw_buf_t disp_buf;
static lv_disp_drv_t disp_drv;

void init_st7796(void){
    
    setup_pwm(LCD_PIN_BL);

    ESP_LOGI("st7796", "Initialize SPI bus");
    spi_bus_config_t buscfg = {
        .mosi_io_num = LCD_PIN_MOSI,
        .miso_io_num = LCD_PIN_MISO,
        .sclk_io_num = LCD_PIN_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = LCD_WIDTH * 80 * sizeof(lv_color_t),
    };
    ESP_ERROR_CHECK(spi_bus_initialize(LCD_HOST, &buscfg, SPI_DMA_CH_AUTO));

    ESP_LOGI("st7796", "Install panel IO");
    esp_lcd_panel_io_handle_t io_handle = NULL;
    esp_lcd_panel_io_spi_config_t io_config = {
        .cs_gpio_num = LCD_PIN_CS,
        .dc_gpio_num = LCD_PIN_DC,
        .spi_mode = 0,
        .pclk_hz = EXAMPLE_LCD_PIXEL_CLOCK_HZ,
        .trans_queue_depth = 10,
        .on_color_trans_done = example_notify_lvgl_flush_ready,
        .user_ctx = &disp_drv,
        .lcd_cmd_bits = EXAMPLE_LCD_CMD_BITS,
        .lcd_param_bits = EXAMPLE_LCD_PARAM_BITS,
    };

    // Attach the LCD to the SPI bus
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)LCD_HOST, &io_config, &io_handle));

    esp_lcd_panel_handle_t panel_handle = NULL;
    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = LCD_PIN_RST,
        .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_BGR,
        .bits_per_pixel = 16,
    };

    ESP_LOGI("st7796", "Install st7796 panel driver");
    ESP_ERROR_CHECK(esp_lcd_new_panel_st7796(io_handle, &panel_config, &panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_invert_color(panel_handle, true));
    // ESP_ERROR_CHECK(esp_lcd_panel_mirror(panel_handle, false, false));
    ESP_ERROR_CHECK(esp_lcd_panel_swap_xy(panel_handle, true));

    // user can flush pre-defined pattern to the screen before we turn on the screen or backlight
    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(panel_handle, true));

    ESP_LOGI("st7796", "Initialize LVGL library");
    lv_init();
    // alloc draw buffers used by LVGL
    // it's recommended to choose the size of the draw buffer(s) to be at least 1/10 screen sized
    lv_color_t *buf1 = (lv_color_t*)heap_caps_malloc(LCD_HEIGHT * 40 * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf1);
    lv_color_t *buf2 = (lv_color_t*)heap_caps_malloc(LCD_HEIGHT * 40 * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf2);

    ESP_LOGI("st7796","Free DMA heap size: %d bytes\n", heap_caps_get_free_size(MALLOC_CAP_DMA));

    // initialize LVGL draw buffers
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, LCD_HEIGHT * 40);

    ESP_LOGI("st7796", "Register display driver to LVGL");
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = LCD_HEIGHT;
    disp_drv.ver_res = LCD_WIDTH;
    disp_drv.flush_cb = example_lvgl_flush_cb;
    disp_drv.draw_buf = &disp_buf;
    disp_drv.user_data = panel_handle;
    


    ESP_LOGI("st7796", "Install LVGL tick timer");
    // Tick interface for LVGL (using esp_timer to generate 2ms periodic event)
    const esp_timer_create_args_t lvgl_tick_timer_args = {
        .callback = &example_increase_lvgl_tick,
        .name = "lvgl_tick"
    };
    esp_timer_handle_t lvgl_tick_timer = NULL;
    ESP_ERROR_CHECK(esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(lvgl_tick_timer, EXAMPLE_LVGL_TICK_PERIOD_MS * 1000)); // periodicly trigger LVGL timer

}


static void touch_callback(esp_lcd_touch_handle_t tp)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(touch_mux, &xHigherPriorityTaskWoken);

    if (xHigherPriorityTaskWoken) {
        portYIELD_FROM_ISR();
    }
}

static void example_lvgl_touch_cb(lv_indev_drv_t * drv, lv_indev_data_t * data){   
    // ESP_LOGI(TAG,"asdasdas");

    if (xSemaphoreTake(touch_mux, 0) != pdTRUE){
        return;
    }

    uint16_t touchpad_x[1] = {0};
    uint16_t touchpad_y[1] = {0};
    uint8_t touchpad_cnt = 0;

    esp_lcd_touch_handle_t panel_handle = (esp_lcd_touch_handle_t) drv->user_data;

    /* Read touch controller data */
    esp_lcd_touch_read_data(panel_handle);

    /* Get coordinates */
    bool touchpad_pressed = esp_lcd_touch_get_coordinates(panel_handle, touchpad_x, touchpad_y, NULL, &touchpad_cnt, 1);

    // ESP_LOGI(TAG, "Touchpad count: %d", touchpad_cnt); 

    if (touchpad_pressed && touchpad_cnt > 0) {
        data->point.x = touchpad_x[0];
        data->point.y = touchpad_y[0];
        data->state = LV_INDEV_STATE_PRESSED;
        // printf("X: %d Y: %d\n",data->point.x,data->point.y);
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}


void init_ft6336u(void){
    /*Initialization of the touch component*/

    // Initial I2C master bus
    i2c_master_bus_config_t i2c_mst_config = {
        .i2c_port = -1,
        .sda_io_num = TOUCH_SDA,
        .scl_io_num = TOUCH_SCL,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
    };
    i2c_master_bus_handle_t bus_handle;
    ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_mst_config, &bus_handle));

    esp_lcd_touch_handle_t tp = NULL;
    esp_lcd_panel_io_handle_t tp_io_handle = NULL;
    esp_lcd_panel_io_i2c_config_t tp_io_config = ESP_LCD_TOUCH_IO_I2C_FT6336U_CONFIG();

    i2c_device_config_t dev_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = tp_io_config.dev_addr,
        .scl_speed_hz = I2C_FREQ,
    };
    i2c_master_dev_handle_t device;
    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &dev_cfg, &device));

    ESP_ERROR_CHECK(esp_lcd_new_panel_io_i2c(bus_handle, &tp_io_config, &tp_io_handle));

    esp_lcd_touch_config_t tp_cfg = {
        .x_max = LCD_WIDTH,
        .y_max = LCD_HEIGHT,
        .rst_gpio_num = TOUCH_RST,
        .int_gpio_num = TOUCH_IRQ,
        .levels = {
            .reset = 0,
            .interrupt = 0,
        },
        .flags = {
            .swap_xy = 1,
            .mirror_x = 1,
            .mirror_y = 0,
        },
        .interrupt_callback = touch_callback,
    };

    ESP_LOGI(TAG, "Initialize touch controller ft6336u");

    // 初始化觸摸控制器
    esp_lcd_touch_new_i2c_ft6336u(tp_io_handle, &tp_cfg, &tp);

    // Lvgl driver handler
    lv_disp_t *disp = lv_disp_drv_register(&disp_drv);

    static lv_indev_drv_t indev_drv;    // Input device driver (Touch)
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.disp = disp;
    indev_drv.read_cb = example_lvgl_touch_cb;
    indev_drv.user_data = tp;
    lv_indev_drv_register(&indev_drv);
}




void update_channels_on_screen(lv_ui *ui, SensorData_t *sensor_data){
    if (ui==NULL||sensor_data==NULL) return;
    lv_bar_set_value(ui->screen_MeasurePage_bar_humidity, sensor_data->humidity, LV_ANIM_OFF);
    lv_bar_set_value(ui->screen_MeasurePage_bar_temperature, sensor_data->temperature, LV_ANIM_OFF);
    lv_bar_set_value(ui->screen_MeasurePage_bar_pressure, (sensor_data->pressure)/50, LV_ANIM_OFF);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch1, (sensor_data->resistance[0]>>2), LV_ANIM_OFF);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch2, (sensor_data->resistance[1]>>8), LV_ANIM_OFF);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch3, (sensor_data->resistance[2]>>4), LV_ANIM_OFF);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch4, (sensor_data->resistance[3]<<1), LV_ANIM_OFF);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch5, (sensor_data->resistance[4]>>9), LV_ANIM_OFF);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch6, (sensor_data->resistance[5]>>14), LV_ANIM_OFF);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch7, (sensor_data->resistance[6]>>3), LV_ANIM_OFF);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch8, (sensor_data->resistance[7]>>3), LV_ANIM_OFF);


    char buf[64];  // 用於存儲格式化的字符串

    // 將數值轉換為字符串
    snprintf(buf, sizeof(buf), "%d", sensor_data->humidity);
    lv_label_set_text(ui->screen_MeasurePage_label_humidity, buf);

    snprintf(buf, sizeof(buf), "%d", sensor_data->temperature);
    lv_label_set_text(ui->screen_MeasurePage_label_temperature, buf);

    snprintf(buf, sizeof(buf), "%.2f", sensor_data->pressure);
    lv_label_set_text(ui->screen_MeasurePage_label_pressure, buf);

}


static void textarea_event_handler(lv_event_t * e){      

    lv_obj_t *ta = lv_event_get_target(e);
    lv_obj_t *btnm = lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);


    if (code == LV_EVENT_READY){
        printf("The current text is: %s\n", lv_textarea_get_text(ta));
    }
    else if (code == LV_EVENT_FOCUSED){
        lv_obj_clear_flag(btnm, LV_OBJ_FLAG_HIDDEN);
    }
    else if (code == LV_EVENT_DEFOCUSED){
        lv_obj_add_flag(btnm, LV_OBJ_FLAG_HIDDEN);
    }
}

static void btnm_event_handler(lv_event_t * e) {

    lv_obj_t * btnm = lv_event_get_target(e);
    lv_obj_t * ta = lv_event_get_user_data(e);
    const char * txt = lv_btnmatrix_get_btn_text(btnm, lv_btnmatrix_get_selected_btn(btnm));

    if(strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) lv_textarea_del_char(ta);
    else if(strcmp(txt, LV_SYMBOL_NEW_LINE) == 0) {
        lv_event_send(ta, LV_EVENT_READY, NULL);
        lv_obj_add_flag(btnm, LV_OBJ_FLAG_HIDDEN);
    }
    else if(strcmp(txt, "#abc-1") == 0){
        lv_btnmatrix_set_map(btnm, btnm_map_eng_1);
    }
    else if(strcmp(txt, "#abc-2") == 0){
        lv_btnmatrix_set_map(btnm, btnm_map_eng_2);
    }
    else if(strcmp(txt, "#abc-3") == 0){
        lv_btnmatrix_set_map(btnm, btnm_map_eng_3);
    }
    else if(strcmp(txt, "#num") == 0){
        lv_btnmatrix_set_map(btnm, btnm_map_num);
    }
    else lv_textarea_add_text(ta, txt);
}

void lv_init_keyboard(lv_ui *ui) {

    lv_obj_t *btnm = lv_btnmatrix_create(ui->screen_SettingPage);
    lv_obj_set_size(btnm, 480, 200);
    lv_obj_set_pos(btnm, 0, 120);
    lv_btnmatrix_set_map(btnm, btnm_map_num);

    lv_obj_add_event_cb(btnm, btnm_event_handler, LV_EVENT_VALUE_CHANGED, ui->screen_SettingPage_ta_sampleText);
    lv_obj_add_event_cb(ui->screen_SettingPage_ta_sampleText, textarea_event_handler, LV_EVENT_READY, btnm);
    lv_obj_add_event_cb(ui->screen_SettingPage_ta_sampleText, textarea_event_handler, LV_EVENT_FOCUSED, btnm);
    lv_obj_add_event_cb(ui->screen_SettingPage_ta_sampleText, textarea_event_handler, LV_EVENT_DEFOCUSED, btnm);

    lv_obj_clear_flag(btnm, LV_OBJ_FLAG_CLICK_FOCUSABLE);
    lv_obj_add_flag(btnm, LV_OBJ_FLAG_HIDDEN);

}


void lv_msgbox(const char *message) {

    lv_obj_t * mbox1 = lv_msgbox_create(lv_scr_act(), "Error", message, NULL, true);
    lv_obj_set_size(mbox1, 200, 120);
    lv_obj_center(mbox1);

    lv_obj_t *content = lv_msgbox_get_text(mbox1);
    lv_obj_set_style_text_align(content, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN); // 文字居中對齊

    lv_obj_t *close_btn = lv_msgbox_get_close_btn(mbox1);
    lv_obj_set_size(close_btn, 30, 30); // 放大按鈕

}

bool file_exists(const char *path) {
    FILE *file = fopen(path, "r");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}


void create_csv_file(const char *path) {
    FILE *file = fopen(path, "w"); 
    if (file == NULL) {
        ESP_LOGE("mylvgl.c", "cannot create file: %s", path);
        return;
    }

    fprintf(file, "Time,Index,State,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,humi,temp,pressure\n");  // CSV title
    printf("Time,Index,State,ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,humi,temp,pressure\n");
    fclose(file);

}

void write_csv_data(int count, const char *state, SensorData_t sensor_value, const char *path)  {
    FILE *file = fopen(path, "a");  
    if (file == NULL) {
        ESP_LOGE("SPIFFS", "cannot open file: %s", path);
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char time_str[9]; 
    strftime(time_str, sizeof(time_str), "%H:%M:%S", t);

    static char buffer[128]; 
    setvbuf(file, buffer, _IOFBF, sizeof(buffer));

    fprintf(file, "%s,%d,%s,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%d,%d,%.2f\n", 
        time_str, count, state,
        sensor_value.resistance[0], sensor_value.resistance[1], 
        sensor_value.resistance[2], sensor_value.resistance[3], 
        sensor_value.resistance[4], sensor_value.resistance[5], 
        sensor_value.resistance[6], sensor_value.resistance[7], 
        sensor_value.humidity, sensor_value.temperature, 
        sensor_value.pressure);
    printf("%s,%d,%s,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%d,%d,%.2f\n", 
        time_str,count, state,
        sensor_value.resistance[0], sensor_value.resistance[1], 
        sensor_value.resistance[2], sensor_value.resistance[3], 
        sensor_value.resistance[4], sensor_value.resistance[5], 
        sensor_value.resistance[6], sensor_value.resistance[7], 
        sensor_value.humidity, sensor_value.temperature, 
        sensor_value.pressure);  
    fflush(file);
    fclose(file);
}
