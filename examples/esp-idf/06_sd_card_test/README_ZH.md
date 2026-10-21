# 06_sd_card_test

[English](README.md) | [简体中文](README_ZH.md)

## 功能

通过 SPI 挂载 microSD 卡并读写测试文件。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

在本目录打开受支持的 ESP-IDF 终端：

```sh
idf.py set-target esp32
idf.py build flash monitor
```

## 预期现象

串口监视器输出卡信息与测试文件内容。

## 常见问题

上电前插入 FAT 格式卡；默认不在挂载失败时格式化。

