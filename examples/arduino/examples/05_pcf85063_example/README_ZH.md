# 05_pcf85063_example

[English](README.md) | [简体中文](README_ZH.md)

## 功能

设置、读取 PCF85063 日期时间，并演示 Unix 时间转换。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

安装仓库首页所列 Arduino-ESP32 版本，将随附库复制到草图本的 `libraries` 目录。选择 **ESP32 Dev Module**、16 MB Flash、QIO、启用 PSRAM，以及 **16M Flash (3MB APP/9.9MB FATFS)**，打开 `.ino` 文件并上传。

## 预期现象

串口输出 RTC 及转换后的时间。

## 常见问题

草图上电后会设置演示用初始日期。

