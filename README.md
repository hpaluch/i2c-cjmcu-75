# Using I2C board CJMCU-75 with LM75A

Here is sample project how to use [CJMCU-75 board][CJMCU-75]
with [I2C LM75A Digital Temperature Sensor][LM75A].

> WARNING!
>
> Work in progress.

![CJMCU-75 Top](https://github.com/hpaluch/i2c-cjmcu-75/blob/master/assets/cjmcu-75-top.jpg?raw=true) 

# Setup 

You need to set I2C Device address before using [CJMCU-75][CJMCU-75].

![CJMCU-75 Bottom](https://github.com/hpaluch/i2c-cjmcu-75/blob/master/assets/cjmcu-75-bottom.jpg?raw=true) 

I set device address to `0` soldering these pins (see above picture):

1. `A0` and `GND` together.
1. `A1` and `GND` together.
1. `A2` and `GND` together.

After soldering all three pins - `A0`, `A1` and `A2` to one of `GND`
or `VCC` the board is ready for use.


[LM75A]: http://www.ti.com/lit/ds/symlink/lm75a.pdf
[CJMCU-75]: https://www.amazon.de/gp/product/B01FQWN79W/
