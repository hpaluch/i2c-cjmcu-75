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

Here is table how to connect together:
* [CH341A USB to UART/IIC/SPI/TTL/ISP adapter EPP/MEM Parallel converter][CH341A USB to UART/IIC/SPI/TTL/ISP adapter EPP/MEM Parallel converter]
* [CJMCU-75 board][Using I2C board CJMCU-75 with LM75A]
* optional: [KeeYees USB Logic Analyzer ][KeeYees USB Logic Analyzer mit 12er 6 Farben Prüf Test Clips Set]:


Wire all 3 things together using table below:

|CH341A pin|Direction from CH341A|CJMCU-75 pin|Logic Analyzer Pin|Description|
|----------|---------------------|------------|------------------|-----------|
|GND|N/A|GND|GND|Common ground|
|SDA|Open Drain|SDA|CH2|I2C SDA|
|SCL|Open Drain|SCL|CH1|I2C SCL|
|VCC|N/A|VCC|NC|+5V Supply from LC CH341A USB Adapter|

NOTE: `NC` means "not connected"

Example program output:

```
Program version: 0.1.0
CH341 library version: 33
Opening device# 0
CH341 driver  version: 34
tempRaw is 6336 (0x18c0)
Used tempRaw is 6272 (0x1880)
Int Temp is 24 degrees of Celsius
Temp is 24.5 degrees of Celsius
```

Please notice that original tempRaw value (0x18c0) has 
one unused bit set (0x40). Useful tempRaw value is thus 0x1880 without
this bit. 

Here is Logical Analzyer output:

![PulseView I2C LM75A Read Temperature](https://github.com/hpaluch/i2c-cjmcu-75/blob/master/ch341-i2c-lm75a/assets/sigrok-ch341-i2c-read-temp.png?raw=true)

NOTE: There exist `LM75` decoder in PulseView, but it does not work
for `LM75A`. It seems that the format of data probably changed.


[KeeYees USB Logic Analyzer mit 12er 6 Farben Prüf Test Clips Set]: https://www.amazon.de/KeeYees-Logic-Analyzer-Farben-Arduino/dp/B07K6G55WG/
[Using I2C board CJMCU-75 with LM75A]:  https://github.com/hpaluch/i2c-cjmcu-75
[Accessing Microwire EEPROM 93LC86 from LC CH341A USB using SPI mode]: https://github.com/hpaluch/ch341-spi-93lc86 
[CH341A USB to UART/IIC/SPI/TTL/ISP adapter EPP/MEM Parallel converter]: http://www.chinalctech.com/cpzx/Programmer/Serial_Module/2019/0124/266.html 
