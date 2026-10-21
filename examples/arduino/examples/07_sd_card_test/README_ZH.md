# 07_sd_card_test

[English](README.md) | [简体中文](README_ZH.md)

## 功能

列举、创建、读取及写入 microSD 文件。

## 硬件需求

ESP32-Touch-LCD-3.5、USB-C 数据线，以及上述功能所用板载外设。

## 怎么运行

安装仓库首页所列 Arduino-ESP32 版本，将随附库复制到草图本的 `libraries` 目录。选择 **ESP32 Dev Module**、16 MB Flash、QIO、启用 PSRAM，分区方案选 **Custom**；保留草图目录内随附的 `partitions.csv`（12 MB 应用分区），打开 `.ino` 文件并上传。

## 预期现象

串口显示文件系统操作及结果。

## 常见问题

复位前插入 FAT 格式 microSD 卡。

