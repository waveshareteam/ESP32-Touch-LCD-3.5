# Firmware

[English](README.md) | [简体中文](README_ZH.md)

This directory provides the latest verified factory firmware for ESP32-Touch-LCD-3.5. Flash the merged image at **0x0**; it includes the bootloader, partition table, application and speech model.

| File | Purpose |
| --- | --- |
| [ESP32-Touch-LCD-3.5_FactoryOnly_20261021.bin](ESP32-Touch-LCD-3.5_FactoryOnly_20261021.bin) | 11-application factory desktop with Button Test, Display Test and backlight enabled after the first frame; ESP-IDF v5.5.4 |

Flash with esptool:

```bash
python -m pip install esptool
python -m esptool --chip esp32 --port PORT write_flash 0x0 ESP32-Touch-LCD-3.5_FactoryOnly_20261021.bin
```

Run from this directory and replace `PORT` with the board's serial port.

SHA256 (20261021): `27b419a5388c9ff2d7045b87abc10514e45c5c519204c50f0b0b07a886f58cc8`.

Factory source and build instructions are available in [examples/factory](../examples/factory/).
