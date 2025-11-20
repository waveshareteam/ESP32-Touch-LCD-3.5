/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>

#include "driver/gpio.h"
#include "driver/i2c_master.h"
#include "esp_check.h"
#include "esp_log.h"

#include "SensorPCF85063.hpp"

#define I2C_PORT_NUM 0
#define EXAMPLE_PIN_I2C_SDA GPIO_NUM_21
#define EXAMPLE_PIN_I2C_SCL GPIO_NUM_22

SensorPCF85063 rtc;
i2c_master_bus_handle_t i2c_bus_handle;
extern "C" void app_main(void)
{
    i2c_master_bus_config_t i2c_mst_config = {};
    i2c_mst_config.clk_source = I2C_CLK_SRC_DEFAULT;
    i2c_mst_config.i2c_port = (i2c_port_num_t)I2C_PORT_NUM;
    i2c_mst_config.scl_io_num = EXAMPLE_PIN_I2C_SCL;
    i2c_mst_config.sda_io_num = EXAMPLE_PIN_I2C_SDA;
    i2c_mst_config.glitch_ignore_cnt = 7;
    i2c_mst_config.flags.enable_internal_pullup = 1;

    ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_mst_config, &i2c_bus_handle));

    while (!rtc.begin(i2c_bus_handle, PCF85063_SLAVE_ADDRESS))
    {
        printf("Failed to find PCF8563 - check your wiring!\r\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    RTC_DateTime datetime = rtc.getDateTime();

    if (datetime.year < 2025)
    {
        datetime.year = 2025;
        datetime.month = 1;
        datetime.day = 1;
        datetime.hour = 12;
        datetime.minute = 0;
        datetime.second = 0;
        rtc.setDateTime(datetime.year, datetime.month, datetime.day, datetime.hour, datetime.minute, datetime.second);
    }
    rtc.start();

    while (1)
    {
        RTC_DateTime datetime = rtc.getDateTime();
        printf("Date: %04d-%02d-%02d ", datetime.year, datetime.month, datetime.day);
        printf("Time: %02d:%02d:%02d\r\n", datetime.hour, datetime.minute, datetime.second);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
