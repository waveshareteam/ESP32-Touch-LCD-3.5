#pragma once

#include <stdio.h>
#include "driver/i2c_master.h"


#ifdef __cplusplus
extern "C" {
#endif

void esp_es8311_port_init(i2c_master_bus_handle_t bus_handle);
void esp_es8311_test(void);
void esp_es8311_recording(uint8_t *data, size_t limit_size);
void esp_es8311_playing(uint8_t *data, size_t limit_size);

#ifdef __cplusplus
}
#endif

