#ifndef __ESP_SPI_PORT_H__
#define __ESP_SPI_PORT_H__

#include "driver/gpio.h"
#include "driver/spi_master.h"

#define EXAMPLE_SPI_HOST SPI2_HOST


#define EXAMPLE_PIN_LCD_MISO GPIO_NUM_19
#define EXAMPLE_PIN_LCD_MOSI GPIO_NUM_23
#define EXAMPLE_PIN_LCD_SCLK GPIO_NUM_18



#ifdef __cplusplus
extern "C" {
#endif

void esp_spi_port_init(size_t max_transfer_sz);

#ifdef __cplusplus
}
#endif

#endif