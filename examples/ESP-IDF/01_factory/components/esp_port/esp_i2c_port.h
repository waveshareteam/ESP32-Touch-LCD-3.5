#ifndef __ESP_I2C_PORT_H__
#define __ESP_I2C_PORT_H__ 

#include "driver/gpio.h"
#include "driver/i2c_master.h"


#define I2C_PORT_NUM 0
#define EXAMPLE_PIN_I2C_SDA GPIO_NUM_21
#define EXAMPLE_PIN_I2C_SCL GPIO_NUM_22

#ifdef __cplusplus
extern "C" {
#endif

void esp_i2c_port_init(i2c_master_bus_handle_t *i2c_bus_handle);


#ifdef __cplusplus
}
#endif


#endif