<div align="center">
  <h1>ESP32-Touch-LCD-3.5</h1>
  <p><strong>ESP32 3.5 英寸 320 × 480 SPI 电容触摸 LCD 开发板</strong></p>
  <p><a href="README.md">English</a> | <a href="README_ZH.md">简体中文</a></p>
  <p>
    <a href="https://github.com/waveshareteam/ESP32-Touch-LCD-3.5/actions/workflows/build.yml"><img alt="Build" src="https://github.com/waveshareteam/ESP32-Touch-LCD-3.5/actions/workflows/build.yml/badge.svg"></a>
    <a href="https://github.com/waveshareteam/ESP32-Touch-LCD-3.5/releases"><img alt="Latest Release" src="https://img.shields.io/github/v/release/waveshareteam/ESP32-Touch-LCD-3.5"></a>
    <a href="LICENSE"><img alt="License" src="https://img.shields.io/github/license/waveshareteam/ESP32-Touch-LCD-3.5"></a>
  </p>
  <p>
    <a href="https://www.waveshare.net/shop/ESP32-Touch-LCD-3.5.htm">🌐 产品</a> &middot;
    <a href="firmware/">📦 固件</a> &middot;
    <a href="examples/esp-idf/">🧩 ESP-IDF</a> &middot;
    <a href="examples/arduino/examples/">🔧 Arduino</a> &middot;
    <a href="https://docs.waveshare.net/ESP32-Touch-LCD-3.5/">📚 文档</a>
  </p>
  <p><img src="docs/images/ESP32-Touch-LCD-3.5.jpg" alt="ESP32-Touch-LCD-3.5" width="500"></p>
</div>

---

## ✨ 概述

本开发板采用经典 ESP32，集成触摸屏、音频、电源管理和硬件 RTC。本仓库提供新版出厂 APP、ESP-IDF 与 Arduino 示例，以及固件和硬件资料。

产品提供带电池与不带电池的版本，使用相同示例。V1.1 与 V1.2 硬件版本的程序通用。

| 器件 | 规格 / 接口 |
| --- | --- |
| 主控 | ESP32-D0WDR2-V3，双核 LX6，最高 240 MHz |
| 存储 | 16 MB Flash，2 MB PSRAM |
| 显示 | 3.5 英寸 IPS，320 × 480，ST7796，SPI |
| 触摸 | FT6336，I2C 电容触摸 |
| 音频 | ES8311、麦克风、扬声器接口 |
| 电源 / 时钟 | AXP2101 / PCF85063 RTC |
| 扩展 | microSD、TCA9554、USB-C 转串口、GPIO 排座 |
| 无线 | 2.4 GHz Wi-Fi，Bluetooth 4.2（经典蓝牙及 BLE） |

## 📦 快速开始

1. 使用 USB-C 数据线连接开发板。
2. 在 [firmware](firmware/) 下载文件名带 `FactoryOnly` 的出厂合并 BIN。
3. 使用 Flash Download Tool 选择 **ESP32**，在 `0x0` 地址烧录完整合并镜像；更换分区布局前先擦除 Flash。
4. 复位进入桌面，在 Settings 配网，再打开 AIChats 完成激活。

[新版出厂源码](examples/factory/README_ZH.md)包含 Settings、AIChats、Touch Test、Photos、Weather、Music、Sensor（仅 RTC）、2048 和 Mic Test。默认连接 2.4 GHz 热点 `weather-wifi`，密码 `12345678`；也可在 Settings 扫码配网。[旧版出厂示例](examples/esp-idf/01_factory/README_ZH.md)保留供参考。

示例固件包可从 [Releases](https://github.com/waveshareteam/ESP32-Touch-LCD-3.5/releases) 获取；其烧录脚本和说明随包提供。

## 🧪 示例

### ESP-IDF

| 示例 | 功能 |
| --- | --- |
| [01_factory](examples/esp-idf/01_factory/README_ZH.md) | 旧版出厂演示：触摸绘画、设置、RTC 和媒体。 |
| [02_axp2101_example](examples/esp-idf/02_axp2101_example/README_ZH.md) | 读取 AXP2101 电源状态并处理其中断事件。 |
| [03_button_power_save](examples/esp-idf/03_button_power_save/README_ZH.md) | 使用 GPIO0 BOOT 按键演示按键事件及省电功能。 |
| [04_pcf85063_example](examples/esp-idf/04_pcf85063_example/README_ZH.md) | 设置并读取 PCF85063 硬件 RTC。 |
| [05_tca9554_example](examples/esp-idf/05_tca9554_example/README_ZH.md) | 通过 Unity 测试验证 TCA9554 I/O 扩展器。 |
| [06_sd_card_test](examples/esp-idf/06_sd_card_test/README_ZH.md) | 通过 SPI 挂载 microSD 卡并读写测试文件。 |
| [07_lvgl_example](examples/esp-idf/07_lvgl_example/README_ZH.md) | 显示 LVGL 控件并响应电容触摸。 |
| [08_lvgl_audio_play](examples/esp-idf/08_lvgl_audio_play/README_ZH.md) | 通过 LVGL 音乐界面操作 ES8311，播放 microSD 音频。 |
| [09_lvgl_image](examples/esp-idf/09_lvgl_image/README_ZH.md) | 使用 LVGL 显示内置图片并初始化触摸。 |

### Arduino

| 示例 | 功能 |
| --- | --- |
| [01_i2s_audio](examples/arduino/examples/01_i2s_audio/README_ZH.md) | 使用 ES8311 播放 microSD 中的 /music/1.mp3。 |
| [02_axp2101_example](examples/arduino/examples/02_axp2101_example/README_ZH.md) | 查看 AXP2101 电源与电池状态。 |
| [03_button_example](examples/arduino/examples/03_button_example/README_ZH.md) | 输出 BOOT 与 PWR 按键的单击、双击和长按事件。 |
| [04_es8311_example](examples/arduino/examples/04_es8311_example/README_ZH.md) | 测试 ES8311 的 I2S 录音与播放。 |
| [05_pcf85063_example](examples/arduino/examples/05_pcf85063_example/README_ZH.md) | 设置、读取 PCF85063 日期时间，并演示 Unix 时间转换。 |
| [06_tca9554_example](examples/arduino/examples/06_tca9554_example/README_ZH.md) | 测试 TCA9554 I/O 扩展器输出。 |
| [07_sd_card_test](examples/arduino/examples/07_sd_card_test/README_ZH.md) | 列举、创建、读取及写入 microSD 文件。 |
| [08_gfx_helloworld](examples/arduino/examples/08_gfx_helloworld/README_ZH.md) | 使用 Arduino_GFX 绘制文字和图形。 |
| [09_lvgl_basic](examples/arduino/examples/09_lvgl_basic/README_ZH.md) | 显示带触摸开关的 LVGL 9 基础界面。 |
| [10_lvgl_arduino_v9](examples/arduino/examples/10_lvgl_arduino_v9/README_ZH.md) | 演示 LVGL 9 显示缓冲和电容触摸。 |
| [11_bt_music_receiver_arduino_i2s](examples/arduino/examples/11_bt_music_receiver_arduino_i2s/README_ZH.md) | 接收经典蓝牙 A2DP 音频并显示曲目信息。 |

公共库见 [examples/arduino/libraries](examples/arduino/libraries/)。

## 🛠️ 开发环境

| 框架 | 版本 | 示例数 |
| --- | --- | ---: |
| ESP-IDF | v5.5.6、v6.1 | 9 |
| Arduino-ESP32 | 3.3.12 | 11 |
| 新版出厂工程 | ESP-IDF v5.5.4、LVGL 9.6.0~1 | 1 |

版本与 Arduino 开发板选项定义在 [product.json](.github/product.json)。Arduino 示例统一使用随附 LVGL 9 库；请将随附库和共享 `lv_conf.h` 放入草图本的 `libraries` 目录。

## 📚 资料

- [V1.1 原理图](hardware/schematic/ESP32-Touch-LCD-3.5-Schematic-V1.1.pdf)
- [V1.2 原理图](hardware/schematic/ESP32-Touch-LCD-3.5-Schematic-V1.2.pdf)
- [产品详情页](https://www.waveshare.net/shop/ESP32-Touch-LCD-3.5.htm)
- [Wiki](https://docs.waveshare.net/ESP32-Touch-LCD-3.5/)

## 🤝 支持

- 产品使用及技术问题：[微雪技术支持](https://docs.waveshare.net/ESP32-Touch-LCD-3.5/Technical-Support/)。

## 📄 许可证

第一方代码采用 [Apache-2.0](LICENSE)；第三方组件保留各自的许可证及归属声明。

