#pragma once

#include <stdio.h>


#ifdef __cplusplus
extern "C" {
#endif


void esp_sdcard_port_init(void);
uint64_t esp_sdcard_port_get_size(void);


#ifdef __cplusplus
}
#endif

