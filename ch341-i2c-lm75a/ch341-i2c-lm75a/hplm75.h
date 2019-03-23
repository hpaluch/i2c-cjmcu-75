/*
 * hplm75.h - Henryk's universal routines for I2C Digital Temperature sensor LM75A
 *
 * NOTE: This file should have only ANSI C dependencies (not CH341A or WinAPI dependencies)
 *       There are following reasons:
 *       1. All functions shall have coresponding Unit tests
 *       2. These functions will make base for portable LM75A library (someday)
 */
#ifndef HPLM75_H
#define HPLM75_H

// converts raw temperature form I2C LM75A to integer in degrees of Celsius (loses 0.5 precision)
// NOTE: values are always truncated to zero, which means:
//  1.0 => 1
//  0.5 => 0
//  0.0 => 0
// -0.5 => 0
// -1.0 => 1
// -1.5 => 1
//  2.0 => -2
int HpLm75_RawTempToInt(int16_t rawTemp);

// converts Raw LM75 temperature to string, for example
// 1.5 => "1.5"
// -1.5 => "-1.5"
void HpLm75_RawTempToStr(int16_t rawTemp,char *strOut, int strLen);

#endif // HPLM75_H