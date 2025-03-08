# ESP32-S3 Enose Sensor Data Acquisition and Display
This project is designed for the ESP32-S2 microcontroller, utilizing I2C communication to interface with multiple sensors and displaying real-time data on an LCD screen using LVGL.

For the NCKU WTMH Laboratory's E-nose Device Mobilization Development Project 
(original project reference: https://github.com/JimLin0406/E-nose-GUI-MEMS-version/tree/main)

## Graphic User Interface
Used "NXP GUI Guider" to design the framework of UI.

<img src="./media/measPage.png" width="15%"><img src="./media/settingPage.png" width="15%"><img src="./media/keyborad.png" width="15%">

## Project Progress and Pending Tasks
- [x] **I2C Device Initialization & Configuration:**
  - Successfully initialized HS4011, BME280, PCA9547, and MEMS I2C sensors.
  - Configured working modes and parameters for each I2C device.
- [x] **Data Reading & Processing:**
  - Calculated and processed humidity, temperature, pressure data, and resistant.
- [x] **LVGL Display Setup:**
  - Set up CST816S touchscreen and integrated it with LVGL for touch interaction.
- [x] **FreeRTOS Task Management:**
  - Created multiple tasks for I2C data reading, UI updates, and data processing.
  - Distribute task into two core on esp32-s3.
  - Used a queue to manage the transmission and updating of sensor data.
- [ ] **Data Saving Function:**
  - Saving file via SPIFFS.
- [ ] **Design the Analysis Page:**
  - Implement analyais function via embeded qunatized MTL model.
- [ ] **Hardware modification:**
  - Power manage design (via battery).
  - Shell of device.
  - Extra pumps and valves for inhaling/ exhaling target sample.

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
    
#### Software Configuration
Ensure that your sdkconfig has the necessary drivers enabled.
```
#dependencies
  lvgl/lvgl: ^8.3.10
  espressif/esp_lcd_gc9a01: ^2.0.0
  espressif/esp_lcd_touch_cst816s: ^1.0.6
  espressif/esp_lcd_touch: ^1.1.2
```





