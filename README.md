# ESP32-S3 Enose Sensor Data Acquisition and Display
This project is designed for the ESP32-S2 microcontroller, utilizing I2C communication to interface with multiple sensors and displaying real-time data on an LCD screen using LVGL.

為NCKU WTMH實驗室電子鼻裝置行動化開發專案 (原專案參考: https://github.com/JimLin0406/E-nose-GUI-MEMS-version/tree/main)

## Requirements
### Hardware
- ESP32-S3 LCD ESP32-S3-Touch-LCD-1.28
  - ESP32-S3 development board
  - GC9A01 TFT-LCD
  - CST816S touch controller module
- Taiyo Enose (MEMS with I2C slaves)
  - Temperature /Humidity sensor (HS4011)
  - Pressure sensor (BME280)
  - Multiplexer (PCA9547BS)
  - E-nose sensor*8
 
### Sofrware
#### VS code IDE
  - ESP32-IDF (version 5.3.2)
  - LVGL library (version 8.3.10)
#### Software Configuration
Ensure that your sdkconfig has the necessary drivers enabled.
```
#dependencies
  lvgl/lvgl: ^8.3.10
  espressif/esp_lcd_gc9a01: ^2.0.0
  espressif/esp_lcd_touch_cst816s: ^1.0.6
  espressif/esp_lcd_touch: ^1.1.2
```

## Graphic User Interface
Used "NXP GUI Guider" to design the framework of UI.



