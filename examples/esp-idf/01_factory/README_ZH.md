# 01_factory

[English](README.md) | [简体中文](README_ZH.md)

## 功能

旧版出厂演示：触摸绘画、设置、RTC 和媒体。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

在本目录打开受支持的 ESP-IDF 终端：

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## 预期现象

按 BOOT 退出初始触摸测试，进入应用菜单。

## 常见问题

旧版 Wi-Fi 配置在 main/main.cpp，与新版出厂工程独立。

