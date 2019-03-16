# Using I2C board CJMCU-75 with LM75A

Here is sample project how to use [CJMCU-75 board][CJMCU-75]
with [I2C LM75A Digital Temperature Sensor][LM75A].

> WARNING!
>
> Work in progress.

![CJMCU-75 Top](https://github.com/hpaluch/i2c-cjmcu-75/blob/master/assets/cjmcu-75-top.jpg?raw=true) 

# Setup 

Here is reverse engineered schematic (drawn in [Express SCH][Express SCH]) of CJMCU-75 with LM75A address set to `0`:

![CJMCU-75 Schematic](https://github.com/hpaluch/i2c-cjmcu-75/blob/master/assets/ExpressPCB/cjmcu-75.png?raw=true) 

> NOTE:
>
> I was surprised that the resistor labeled `300` is actually
> `200K Ohm` (I would expect `30 * 10^0 = 30 Ohm` which would be strange, but...)
> This is even value which I get
>  on [SMD resistor code calculator][SMD resistor code calculator]

You need to set I2C Device address before using [CJMCU-75][CJMCU-75].

![CJMCU-75 Bottom](https://github.com/hpaluch/i2c-cjmcu-75/blob/master/assets/cjmcu-75-bottom.jpg?raw=true) 

I set device address to `0` soldering these pins (see above picture):

1. `A0` and `GND` together.
1. `A1` and `GND` together.
1. `A2` and `GND` together.

After soldering all three pins - `A0`, `A1` and `A2` to one of `GND`
or `VCC` the board is ready for use.

[Express SCH]: https://www.expresspcb.com/expresspcb/
[SMD resistor code calculator]: https://www.hobby-hour.com/electronics/smdcalc.php
[LM75A]: http://www.ti.com/lit/ds/symlink/lm75a.pdf
[CJMCU-75]: https://www.amazon.de/gp/product/B01FQWN79W/
