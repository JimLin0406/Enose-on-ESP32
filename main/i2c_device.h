// i2c_device.h
#ifndef I2C_DEVICE_H
#define I2C_DEVICE_H

#include "driver/i2c_master.h"

#define I2C_MASTER_SCL_IO    GPIO_NUM_21    // SCL pin
#define I2C_MASTER_SDA_IO    GPIO_NUM_33    // SDA pin

#define HS4011_ADDR                   0x54
#define BME280_ADDR                   0x76
#define PCA9547_ADDR                  0x70 
#define MEMS_ADDR                     0x78
#define I2C_MASTER_FREQ_HZ   100000  // 設置為 100kHz


#ifdef __cplusplus
extern "C" {
#endif




typedef struct {
    uint8_t data[4];
    uint8_t crc;
} HS4011_DATA;

typedef struct {
    i2c_master_dev_handle_t dev_handle;
    uint8_t device_address;
}i2c_device_t;

typedef struct {
    uint16_t ch1; 
    uint16_t ch2; 
    uint16_t ch3;  
    uint16_t ch4;  
    uint16_t ch5; 
    uint16_t ch6;  
    uint16_t ch7;  
    uint16_t ch8;
} MEMS_DATA;


typedef uint32_t BME280_DATA;



enum channel{
    CH1 = 0b00001000,
    CH2 = 0b00001001,
    CH3 = 0b00001010,
    CH4 = 0b00001011,
    CH5 = 0b00001100,
    CH6 = 0b00001101,
    CH7 = 0b00001110,
    CH8 = 0b00001111,
}; // 8 different Enose sensor 


esp_err_t i2c_device_init(i2c_device_t *device, i2c_master_bus_handle_t bus_handle, uint8_t device_address);
esp_err_t read_from_HS4011(i2c_device_t *device,HS4011_DATA *results);
esp_err_t set_BME280_mode(i2c_device_t const *device);
uint8_t CRC8(uint8_t *data, uint8_t length);
esp_err_t read_from_BME280(i2c_device_t *device, BME280_DATA *results);
esp_err_t read_from_MEMS(i2c_device_t *multiplexer,i2c_device_t *devices, MEMS_DATA *results);






#ifdef __cplusplus
}
#endif


#endif // I2C_DEVICE_H