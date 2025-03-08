// i2c_device.c

#include "i2c_device.h"
#include "driver/i2c_master.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "I2C_DEVICE";

// Compensation parameter
int32_t t_fine;
uint16_t dig_T1,dig_P1;
int16_t dig_T2,dig_T3,dig_P2,dig_P3,dig_P4,dig_P5,dig_P6,dig_P7,dig_P8,dig_P9;

// private functions
esp_err_t read16_LE(i2c_device_t const *device, uint8_t reg, uint16_t *value);
esp_err_t readS16_LE(i2c_device_t const *device, uint8_t reg, int16_t *value);
esp_err_t readCalibrationData(i2c_device_t const *device);
int32_t BME280_compensate_T_int32(int32_t adc_T);
uint32_t BME280_compensate_P_int64(int32_t adc_P);

// functions definition
esp_err_t i2c_device_init(i2c_device_t *device, i2c_master_bus_handle_t bus_handle, uint8_t device_address){

    i2c_device_config_t dev_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = device_address,
        .scl_speed_hz = I2C_MASTER_FREQ_HZ,
    };

    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &dev_cfg, &device->dev_handle));
    device->device_address = device_address;

    return ESP_OK;
}

esp_err_t read_from_HS4011(i2c_device_t *device, HS4011_DATA *results){
    esp_err_t ret = ESP_OK;

    uint8_t write_buf[1] = {0xF5};   // Write: No-hold Humidity and Temperature Measurement

    ret = i2c_master_transmit(device->dev_handle,write_buf,sizeof(write_buf), 10);

    if (ret != ESP_OK){
        ESP_LOGE(TAG, "Failed to write to HS4011");
        return ret;
    }
    vTaskDelay(pdMS_TO_TICKS(10));
    uint8_t read_buf[5];

    ret = i2c_master_receive(device->dev_handle, read_buf, sizeof(read_buf), 10);
    if (ret != ESP_OK) {
        ESP_LOGE("I2C", "Failed to read from HS4011");
        return ret; 
    }

    for (int i = 0; i < 4; i++) {
        results->data[i] = read_buf[i];
    }
    results->crc = read_buf[4]; // CRC
    return ret;
}

esp_err_t set_BME280_mode(i2c_device_t const *device){
    esp_err_t ret = ESP_OK;
    uint8_t write_buf[2] = {0xF4, 0x00}; // Fistly make it into sleep mode, and then we can adjust parms

    ret = i2c_master_transmit(device->dev_handle, write_buf, sizeof(write_buf), 10);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to write to BME280 (F4)");
        return ret;
    }
    vTaskDelay(pdMS_TO_TICKS(10));

    uint8_t write_buf2[2] = {0xF5, 0b00001100}; // standy time:0.5ms; filter: 8
    ret = i2c_master_transmit(device->dev_handle, write_buf2, sizeof(write_buf2), 10);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to write to BME280 (F5)");
        return ret;
    }
    vTaskDelay(pdMS_TO_TICKS(10));

    uint8_t write_buf3[2] = {0xF2, 0x00}; // disable humidity measurement
    ret = i2c_master_transmit(device->dev_handle, write_buf3, sizeof(write_buf3), 10);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to write ctrl_hum (0xF2) to BME280");
        return ret;
    }
    vTaskDelay(pdMS_TO_TICKS(10));  

    uint8_t write_buf4[2] = {0xF4, 0b10110111}; // set measurement mode
    ret = i2c_master_transmit(device->dev_handle, write_buf4, sizeof(write_buf4), 10);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to write ctrl_meas (0xF4) to BME280");
        return ret;
    }
    vTaskDelay(pdMS_TO_TICKS(10));

    // read compensation parameter from Non-Volatile registers
    readCalibrationData(device); 

    return ret;
}

esp_err_t read_from_BME280(i2c_device_t *device, BME280_DATA *results){
    esp_err_t ret = ESP_OK;

    uint8_t write_buf[1] = {0xFA}; // Temperature register
    ret = i2c_master_transmit(device->dev_handle, write_buf, sizeof(write_buf), 10);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to write to BME280 (0xFA)");
        return ret;
    }
    vTaskDelay(pdMS_TO_TICKS(10));

    uint8_t read_buf[3];

    ret = i2c_master_receive(device->dev_handle, read_buf, sizeof(read_buf), 10);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to read from BME280 (temperature)");
        return ret;
    }
    vTaskDelay(pdMS_TO_TICKS(10));

    int32_t T_raw = ((int32_t)read_buf[0] << 12) | ((int32_t)read_buf[1] << 4) | (read_buf[2] >> 4);

    uint8_t write_buf2[1] = {0xF7};  // pressure register

    ret = i2c_master_transmit(device->dev_handle, write_buf2, sizeof(write_buf2), 10);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to write to BME280 (0xF7)");
        return ret;
    }
    vTaskDelay(pdMS_TO_TICKS(10)); 

    ret = i2c_master_receive(device->dev_handle, read_buf, sizeof(read_buf), 10);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to read from BME280 (pressure)");
        return ret;
    }
    vTaskDelay(pdMS_TO_TICKS(10));

    int32_t P_raw = ((int32_t)read_buf[0] << 12) | ((int32_t)read_buf[1] << 4) | (read_buf[2] >> 4);

    int32_t compensated_temp = BME280_compensate_T_int32(T_raw);
    int32_t compensated_pressure =  BME280_compensate_P_int64(P_raw);

    *results = (BME280_DATA)compensated_pressure;


    return ret;
}

esp_err_t read_from_MEMS(i2c_device_t *multiplexer,i2c_device_t *devices, MEMS_DATA *results){
    esp_err_t ret = ESP_OK;
    for (int i = 0; i < 8; i++){  
        // Switch channel of multiplexer
        uint8_t write_buf[1] = {CH1 + i}; 
        uint8_t read_buf_RS_L[1],read_buf_RS_H[1],read_buf_RS_OF[1];
        ret = i2c_master_transmit(multiplexer->dev_handle, write_buf, sizeof(write_buf), 10);
        if (ret != ESP_OK) {
            ESP_LOGE(TAG, "Failed to write to switch channel");
            return ret;
        }
        vTaskDelay(pdMS_TO_TICKS(10));

        // Read MEMS registers: Rs Low byte
        uint8_t write_buf1[1] = {0x04}; 
        ret = i2c_master_transmit(devices->dev_handle, write_buf1, sizeof(write_buf1), 10);
        if (ret != ESP_OK){
            ESP_LOGE(TAG, "Failed to write MEMS registers: 0x04");
            return ret;
        }
        vTaskDelay(pdMS_TO_TICKS(10));
        
        ret = i2c_master_receive(devices->dev_handle, read_buf_RS_L, sizeof(read_buf_RS_L), 10);
        if (ret != ESP_OK) {
            ESP_LOGE(TAG, "Failed to read_buf_RS_L");
            return ret;
        }
        vTaskDelay(pdMS_TO_TICKS(10));

        // Read MEMS registers: Rs High byte
        uint8_t write_buf2[1] = {0x05}; 

        ret = i2c_master_transmit(devices->dev_handle, write_buf2, sizeof(write_buf2), 10);
        if (ret != ESP_OK){
            ESP_LOGE(TAG, "Failed to write MEMS registers: 0x05");
            return ret;
        }
        vTaskDelay(pdMS_TO_TICKS(10));
        
        ret = i2c_master_receive(devices->dev_handle, read_buf_RS_H, sizeof(read_buf_RS_H), 10);
        if (ret != ESP_OK) {
            ESP_LOGE(TAG, "Failed to read_buf_RS_H");
            return ret;
        }
        vTaskDelay(pdMS_TO_TICKS(10));

        // Read MEMS registers: overflow
        uint8_t write_buf3[1] = {0x01}; 
        ret = i2c_master_transmit(devices->dev_handle, write_buf3, sizeof(write_buf3), 10);
        if (ret != ESP_OK) {
            ESP_LOGE(TAG, "Failed to write MEMS registers: 0x01");
            return ret;
        }
        vTaskDelay(pdMS_TO_TICKS(10));
        
        ret = i2c_master_receive(devices->dev_handle, read_buf_RS_OF, sizeof(read_buf_RS_OF), 10);
        if (ret != ESP_OK) {
            ESP_LOGE(TAG, "Failed to read_buf_RS_OF");
            return ret;
        }
        vTaskDelay(pdMS_TO_TICKS(10));


        uint16_t resistant = (read_buf_RS_H[0] << 8) | read_buf_RS_L[0]; 

        if (read_buf_RS_OF[0] & 0x80) {
            resistant = resistant<<6;
        }
        *((uint16_t*)(&results->ch1) + i) = resistant;
    }
    return ret;
}





uint8_t CRC8(uint8_t *data, uint8_t length) {
    uint8_t crc = 0xFF; // 初始 CRC 值
    uint8_t polynomial = 0x1D; // CRC-8 多項式 (x^8 + x^4 + x^3 + x + 1)
  
    for (uint8_t i = 0; i < length; i++) {
      crc ^= data[i]; // XOR 當前資料位元組
      for (uint8_t j = 8; j > 0; j--) {
        if (crc & 0x80) {
          crc = (crc << 1) ^ polynomial; // 如果 CRC 高位是 1，則移動並 XOR 多項式
        } else {
          crc <<= 1; // 否則僅左移
        }
      }
    }
    return crc;
  }

esp_err_t read16_LE(i2c_device_t const *device, uint8_t reg, uint16_t *value) {
    esp_err_t ret;
    uint8_t data[2] = {0};

    ret = i2c_master_transmit(device->dev_handle, &reg, 1, 10);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to write register address 0x%02X", reg);
        return ret;
    }

    ret = i2c_master_receive(device->dev_handle, data, 2, 10);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to read register 0x%02X", reg);
        return ret;
    }

    *value = (uint16_t)(data[0] | (data[1] << 8));

    return ESP_OK;
}

esp_err_t readS16_LE(i2c_device_t const *device, uint8_t reg, int16_t *value) {
    uint16_t temp;
    esp_err_t ret = read16_LE(device, reg, &temp);
    if (ret != ESP_OK) {
        return ret;
    }
    *value = (int16_t)temp; 
    return ESP_OK;
}

esp_err_t readCalibrationData(i2c_device_t const *device) {
    esp_err_t ret;

    ret = read16_LE(device, 0x88, &dig_T1);
    if (ret != ESP_OK) return ret;
    ret = readS16_LE(device, 0x8A, &dig_T2);
    if (ret != ESP_OK) return ret;
    ret = readS16_LE(device, 0x8C, &dig_T3);
    if (ret != ESP_OK) return ret;

    ret = read16_LE(device, 0x8E, &dig_P1);
    if (ret != ESP_OK) return ret;
    ret = readS16_LE(device, 0x90, &dig_P2);
    if (ret != ESP_OK) return ret;
    ret = readS16_LE(device, 0x92, &dig_P3);
    if (ret != ESP_OK) return ret;
    ret = readS16_LE(device, 0x94, &dig_P4);
    if (ret != ESP_OK) return ret;
    ret = readS16_LE(device, 0x96, &dig_P5);
    if (ret != ESP_OK) return ret;
    ret = readS16_LE(device, 0x98, &dig_P6);
    if (ret != ESP_OK) return ret;
    ret = readS16_LE(device, 0x9A, &dig_P7);
    if (ret != ESP_OK) return ret;
    ret = readS16_LE(device, 0x9C, &dig_P8);
    if (ret != ESP_OK) return ret;
    ret = readS16_LE(device, 0x9E, &dig_P9);
    if (ret != ESP_OK) return ret;

    return ESP_OK;
}


int32_t BME280_compensate_T_int32(int32_t adc_T) {
    int32_t var1, var2, T;
    var1 = ((((adc_T >> 3) - ((int32_t)dig_T1 << 1))) * ((int32_t)dig_T2)) >> 11;
    var2 = (((((adc_T >> 4) - ((int32_t)dig_T1)) * ((adc_T >> 4) - ((int32_t)dig_T1))) >> 12) * ((int32_t)dig_T3)) >> 14;
    t_fine = var1 + var2;
    T = (t_fine * 5 + 128) >> 8;
    return T; // 溫度值，單位為 0.01°C
}

uint32_t BME280_compensate_P_int64(int32_t adc_P) {
    int64_t var1, var2, p;
    var1 = ((int64_t)t_fine) - 128000;
    var2 = var1 * var1 * (int64_t)dig_P6;
    var2 = var2 + ((var1 * (int64_t)dig_P5) << 17);
    var2 = var2 + (((int64_t)dig_P4) << 35);
    var1 = ((var1 * var1 * (int64_t)dig_P3) >> 8) + ((var1 * (int64_t)dig_P2) << 12);
    var1 = (((((int64_t)1) << 47) + var1)) * ((int64_t)dig_P1) >> 33;
    
    if (var1 == 0) {
        return 0; // 避免除以 0 的錯誤
    }
    
    p = 1048576 - adc_P;
    p = (((p << 31) - var2) * 3125) / var1;
    var1 = (((int64_t)dig_P9) * (p >> 13) * (p >> 13)) >> 25;
    var2 = (((int64_t)dig_P8) * p) >> 19;
    p = ((p + var1 + var2) >> 8) + (((int64_t)dig_P7) << 4);
    
    return (uint32_t)p; // 單位為 Pa
}