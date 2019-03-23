# Connecting I2C board CJMCU-75 with LM75A to PC using LC 341A USB adapter


Please see [master project README][Using I2C board CJMCU-75 with LM75A]:
for Introduction and CJMCU-75 schematic.

Here is VisualStudio 2010 project to control 
[I2C board CJMCU-75 with LM75A][Using I2C board CJMCU-75 with LM75A]
using 
[CH341A USB to UART/IIC/SPI/TTL/ISP adapter EPP/MEM Parallel converter][CH341A USB to UART/IIC/SPI/TTL/ISP adapter EPP/MEM Parallel converter]

Please see one of my CH341 projects, for example
[Accessing Microwire EEPROM 93LC86 from LC CH341A USB using SPI mode][Accessing Microwire EEPROM 93LC86 from LC CH341A USB using SPI mode]
for generic HW/SW setup instructions. Here is project specific info only.


# Wiring LC CH341A USB adapter with [CJMCU-75 board][Using I2C board CJMCU-75 with LM75A]

Wire all 2 things together using table below:

|CH341A pin|Direction from CH341A|CJMCU-75 pin|Description|
|----------|---------------------|------------|-----------|
|GND|N/A|GND|Common ground|
|SDA|Open Drain|SDA|I2C SDA|
|SCL|Open Drain|SCL|I2C SCL|
|VCC|N/A|VCC|+5V Supply from LC CH341A USB Adapter|

Example program output:

```
CH341 library version: 33
Opening device# 0
CH341 driver  version: 34
tempRaw is 6912 (0x1b00)
Int Temp is 27 degrees of Celsius
Temp is 27.0 degrees of Celsius
```

[Using I2C board CJMCU-75 with LM75A]:  https://github.com/hpaluch/i2c-cjmcu-75
[Accessing Microwire EEPROM 93LC86 from LC CH341A USB using SPI mode]: https://github.com/hpaluch/ch341-spi-93lc86 
[CH341A USB to UART/IIC/SPI/TTL/ISP adapter EPP/MEM Parallel converter]: http://www.chinalctech.com/cpzx/Programmer/Serial_Module/2019/0124/266.html 
