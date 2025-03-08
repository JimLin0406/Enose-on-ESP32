// mylvgl.h
#ifndef MYLVGL_H
#define MYLVGL_H

#include "esp_lcd_gc9a01.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "esp_timer.h"
#include "lvgl.h"
#include "driver/ledc.h"
#include "esp_log.h"
#include "freertos/semphr.h"
#include "esp_lcd_touch_cst816s.h"
#include "driver/i2c_master.h"

#include "gui_guider.h"

// 定義觸控屏的引腳配置
#define TOUCH_SDA GPIO_NUM_6
#define TOUCH_SCL GPIO_NUM_7
#define TOUCH_RST GPIO_NUM_13
#define TOUCH_IRQ GPIO_NUM_5
#define I2C_FREQ 100000

// 定義顯示屏配置
#define LCD_PIN_CLK   GPIO_NUM_10
#define LCD_PIN_MISO  GPIO_NUM_12  
#define LCD_PIN_MOSI  GPIO_NUM_11
#define LCD_PIN_CS    GPIO_NUM_9
#define LCD_PIN_RST   GPIO_NUM_14
#define LCD_PIN_DC    GPIO_NUM_8
#define LCD_PIN_BL    GPIO_NUM_2  

#define EXAMPLE_LCD_PIXEL_CLOCK_HZ     (40 * 1000 * 1000)
#define EXAMPLE_LCD_CMD_BITS           8
#define EXAMPLE_LCD_PARAM_BITS         8
#define EXAMPLE_LVGL_TICK_PERIOD_MS    60
#define LCD_HOST  SPI2_HOST

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
    uint16_t humidity;
    uint16_t temperature;
    float pressure;
    uint16_t resistance[8];
} SensorData_t;

typedef struct {
    lv_obj_t * btnm;
    lv_obj_t * ta;
} keyboard_params_t;


/*Create an AZERTY keyboard map*/
static const char * btnm_map_num[] = {"1", "2", "3", "4", "\n",
    "5", "6", "7", "8",  "\n",
    LV_SYMBOL_BACKSPACE, "9", "0", LV_SYMBOL_NEW_LINE, "\n",
    "#abc-1", ""
   };

static const char * btnm_map_eng_1[] = {"a", "b", "c", "d", "\n",
    "e", "f", "g", "h",  "\n",
    LV_SYMBOL_BACKSPACE, "i", "j", LV_SYMBOL_NEW_LINE, "\n",
    "#abc-2", ""
};

static const char * btnm_map_eng_2[] = {"k", "l", "m", "n", "\n",
    "o", "p", "q", "r",  "\n",
    LV_SYMBOL_BACKSPACE, "i", "j", LV_SYMBOL_NEW_LINE, "\n",
    "#abc-3", ""
};

static const char * btnm_map_eng_3[] = {"s", "t", "u", "v", "\n",
    "w", "x", "y", "z",  "\n",
    LV_SYMBOL_BACKSPACE, "_", "-", LV_SYMBOL_NEW_LINE, "\n",
    "#num", ""
};

static bool example_notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx);
static void example_lvgl_flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map);
static void example_increase_lvgl_tick(void *arg);
void setup_pwm(int gpio_lcd_pwm);
void init_gc9a01(void);
static void touch_callback(esp_lcd_touch_handle_t tp);
static void example_lvgl_touch_cb(lv_indev_drv_t * drv, lv_indev_data_t * data);
void init_cst816s(void);
void update_channels_on_screen(lv_ui *ui, SensorData_t *sensor_data);

void lv_init_keyboard(lv_ui *ui);

void GUI_background();




#ifdef __cplusplus
}
#endif


#endif // MYLVGL_H