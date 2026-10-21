# 04_pcf85063_example

[English](README.md) | [简体中文](README_ZH.md)

## 功能

设置并读取 PCF85063 硬件 RTC。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

在本目录打开受支持的 ESP-IDF 终端：

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## 预期现象

串口监视器输出递增的日期和时间。

## 常见问题

示例会设置演示时间，作为时钟使用前请修改初始日期。

