
#include "esp_spi_port.h"

#include "esp_check.h"
#include "esp_log.h"

static const char *TAG = "esp_spi_port";
void esp_spi_port_init(size_t max_transfer_sz)
{
    ESP_LOGI(TAG, "SPI BUS init");
    spi_bus_config_t buscfg = {};
    buscfg.sclk_io_num = EXAMPLE_PIN_LCD_SCLK;
    buscfg.mosi_io_num = EXAMPLE_PIN_LCD_MOSI;
    buscfg.miso_io_num = EXAMPLE_PIN_LCD_MISO;
    buscfg.quadwp_io_num = -1;
    buscfg.quadhd_io_num = -1;
    // buscfg.max_transfer_sz = max_transfer_sz;
    ESP_ERROR_CHECK(spi_bus_initialize(EXAMPLE_SPI_HOST, &buscfg, SPI_DMA_CH_AUTO));
}