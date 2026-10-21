# 05_tca9554_example

[English](README.md) | [简体中文](README_ZH.md)

## 功能

通过 Unity 测试验证 TCA9554 I/O 扩展器。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

在本目录打开受支持的 ESP-IDF 终端：

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## 预期现象

在串口菜单选择测试项，查看测试结果。

## 常见问题

扩展器也控制板载复位与功放信号。

