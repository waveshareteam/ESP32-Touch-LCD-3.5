# 02_axp2101_example

[English](README.md) | [简体中文](README_ZH.md)

## 功能

读取 AXP2101 电源状态并处理其中断事件。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

在本目录打开受支持的 ESP-IDF 终端：

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## 预期现象

串口监视器输出电源与电池信息。

## 常见问题

PMU 输出电压配置必须匹配板载供电电路。

