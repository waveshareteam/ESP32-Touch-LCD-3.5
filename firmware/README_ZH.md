# 固件

[English](README.md) | [简体中文](README_ZH.md)

本目录仅提供 ESP32-Touch-LCD-3.5 最新实测出厂固件。请将合并镜像烧录至 **0x0**，其中已包含引导程序、分区表、应用和语音模型。

| 文件 | 用途 |
| --- | --- |
| [ESP32-Touch-LCD-3.5_FactoryOnly_20261021.bin](ESP32-Touch-LCD-3.5_FactoryOnly_20261021.bin) | 11 应用出厂桌面，新增按键测试、颜色循环测试，首帧完成后点亮背光；ESP-IDF v5.5.4 |

使用 esptool 烧录：

```bash
python -m pip install esptool
python -m esptool --chip esp32 --port PORT write_flash 0x0 ESP32-Touch-LCD-3.5_FactoryOnly_20261021.bin
```

在本目录运行，将 `PORT` 替换为设备的实际串口。

SHA256（20261021）：`27b419a5388c9ff2d7045b87abc10514e45c5c519204c50f0b0b07a886f58cc8`。

出厂源码及编译说明请参照 [examples/factory](../examples/factory/README_ZH.md)。
