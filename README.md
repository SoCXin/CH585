# [CH585](https://github.com/SoCXin/CH585)

* [WCH](http://www.wch.cn/)：[RISC-V](https://github.com/SoCXin/RISC-V)
* [L1R2](https://github.com/SoCXin/Level): 78 MHz 

## [简介](https://github.com/SoCXin/CH585/wiki)

[CH585](https://www.wch.cn/products/CH585.html) 是集成BLE无线通讯和高速USB及NFC的RISC-V MCU微控制器。片上集成了2Mbps低功耗蓝牙BLE通讯模块、USB全速控制器及收发器、USB高速控制器及收发器（480Mbps）、NFC近场通信无线接口、段式LCD驱动模块、LED点阵屏接口、2个SPI、4个串口、14路ADC、触摸按键检测模块等丰富的外设资源。

``` mermaid
gantt
    title WCH SDK
    dateFormat  YYYY-MM-DD
    section Mainline Release
    v1.0           :a1, 2024-06-01, 2024-09-30
    v1.1           :a2, 2024-09-30, 2024-12-30
```

### 关键特性

* 32KHz - 78MHz RISC-V3C,支持RV32IMBC指令集和自扩展指令
* 128KB SRAM + 512KB Flash
* 内置480Mbps高速/全速USB2.0控制器及PHY，支持高/全/低速 Host/Device
* 内置2.4GHz RF收发器和基带及链路控制，支持BLE5.4，支持2Mbps、1Mbps
* 2.4G模式下最高8kHz上报率
* 接收灵敏度-95dBm，可编程+4.5dBm发送功率
* 内置RTC，支持定时和触发两种模式
* 提供近场通信无线接口NFC
* 提供段式LCD控制器接口，可支持112个点（28*4）LCD面板
* 提供LED点阵屏接口，支持1/2/4/8路数据线
* 提供14通道触摸按键
* 提供14通道12位ADC
* 提供4组UART，2组SPI，12路PWM ，1路I2C
* 最低支持1.7V电源电压
* 封装：QFN48T、QFN32、QFN26C3，最多40个GPIO，其中2个支持5V信号输入

## [资源收录](https://github.com/SoCXin)

* [参考资源](src/)
* [参考文档](docs/)
* [参考工程](project/)
* [mounriver开发环境](http://www.mounriver.com/download)

## [选型建议](https://github.com/SoCXin)

[CH585](https://github.com/SoCXin/CH585) 在紧凑的封装内集成了高速USB(480Mbps +PHY)，同时还具有BLE 5.4以及NFC通信。

相对[CH592](https://github.com/SoCXin/CH592)系列的低功耗BLE产品，规格差异体现在：

* 更高主频 78MHz RISC-V3C vs 20MHz RISC-V4C
* 更大内存 128KB SRAM vs 26KB SRAM
* 独有的USB HS 480Mbps
* 已发布的NFC功能及其方案

相对[CH583](https://github.com/SoCXin/CH583)系列的低功耗BLE产品，规格差异体现在：

* 内核差异 78MHz RISC-V3C (RV32IMBC) vs 80MHz RISC-V4A (RV32IMAC)
* 内存差异 128KB SRAM vs 32KB SRAM
* 射频差异 BLE5.4(-95dBm,+4.5dBm) vs BLE5.3(-98dBm,+6dBm)
* 独有的USB HS 480Mbps
* 已发布的NFC功能及其方案