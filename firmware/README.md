# Firmware

[English](README.md) | [简体中文](README_ZH.md)

Merged firmware images for ESP32-Touch-LCD-3.5, flashed at `0x0`. The current factory image has been tested on the board; older images are retained under their original filenames.

| File | Purpose |
| --- | --- |
| `ESP32-Touch-LCD-3.5_FactoryOnly_20261021.bin` | Current factory desktop with nine applications |
| `01_factory.bin` | Legacy factory demo |
| `02_axp2101_example.bin` | AXP2101 power-management example |
| `03_button_power_save.bin` | Button and power-saving example |
| `04_pcf85063_example.bin` | PCF85063 RTC example |
| `05_tca9554_example.bin` | TCA9554 I/O-expander example |
| `06_sd_card_test.bin` | microSD read/write example |
| `07_lvgl_example.bin` | LVGL display example |
| `xiaozhi.bin` | Legacy standalone Xiaozhi firmware |

Flash with esptool:

```bash
python -m pip install esptool
esptool --chip esp32 --port <PORT> erase-flash
esptool --chip esp32 --port <PORT> write-flash 0x0 ESP32-Touch-LCD-3.5_FactoryOnly_20261021.bin
```

The current factory source is in [examples/factory](../examples/factory/). Older binaries are retained for reference and do not represent rebuilds of the updated examples.
