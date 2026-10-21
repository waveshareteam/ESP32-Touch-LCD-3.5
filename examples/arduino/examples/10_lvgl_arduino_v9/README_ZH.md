# 10_lvgl_arduino_v9

[English](README.md) | [简体中文](README_ZH.md)

## 功能

演示 LVGL 9 显示缓冲和电容触摸。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

安装仓库首页所列 Arduino-ESP32 版本，将随附库复制到草图本的 `libraries` 目录。选择 **ESP32 Dev Module**、16 MB Flash、QIO、启用 PSRAM，以及 **16M Flash (3MB APP/9.9MB FATFS)**，打开 `.ino` 文件并上传。

## 预期现象

LCD 显示 LVGL 界面并响应触摸。

## 常见问题

使用随仓库提供的统一 LVGL 9 库及 lv_conf.h。

