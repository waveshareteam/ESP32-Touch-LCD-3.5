# 固件

[English](README.md) | [简体中文](README_ZH.md)

适用于 ESP32-Touch-LCD-3.5 的合并固件，统一从 `0x0` 烧录。新版出厂固件已在开发板上实测，历史镜像保留原文件名。

| 文件 | 用途 |
| --- | --- |
| `ESP32-Touch-LCD-3.5_FactoryOnly_20261021.bin` | 新版九应用出厂桌面 |
| `01_factory.bin` | 旧版出厂演示 |
| `02_axp2101_example.bin` | AXP2101 电源管理示例 |
| `03_button_power_save.bin` | 按键与省电示例 |
| `04_pcf85063_example.bin` | PCF85063 RTC 示例 |
| `05_tca9554_example.bin` | TCA9554 I/O 扩展示例 |
| `06_sd_card_test.bin` | microSD 读写示例 |
| `07_lvgl_example.bin` | LVGL 显示示例 |
| `xiaozhi.bin` | 历史独立小智固件 |

使用 esptool 烧录：

```bash
python -m pip install esptool
esptool --chip esp32 --port <PORT> erase-flash
esptool --chip esp32 --port <PORT> write-flash 0x0 ESP32-Touch-LCD-3.5_FactoryOnly_20261021.bin
```

新版出厂源码位于 [examples/factory](../examples/factory/README_ZH.md)。历史固件仅供参考，并非更新后示例的重新构建产物。
