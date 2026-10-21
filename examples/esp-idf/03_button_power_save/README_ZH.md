# 03_button_power_save

[English](README.md) | [简体中文](README_ZH.md)

## 功能

使用 GPIO0 BOOT 按键演示按键事件及省电功能。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

在本目录打开受支持的 ESP-IDF 终端：

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## 预期现象

串口监视器输出按键事件。

## 常见问题

使用板载 BOOT 按键；除进入下载模式外，不要按住 BOOT 复位。

