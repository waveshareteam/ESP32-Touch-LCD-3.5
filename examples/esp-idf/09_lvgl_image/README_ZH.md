# 09_lvgl_image

[English](README.md) | [简体中文](README_ZH.md)

## 功能

使用 LVGL 显示内置图片并初始化触摸。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

在本目录打开受支持的 ESP-IDF 终端：

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## 预期现象

LCD 显示内置图片。

## 常见问题

图片资源编译进固件，无需 SD 卡。

