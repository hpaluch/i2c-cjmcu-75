/*
 * hplm75.cpp - Henryk's universal routines for I2C Digital Temperature sensor LM75A
 *
 * NOTE: This file should have only ANSI C dependencies (not CH341A or WinAPI dependencies)
 *       There are following reasons:
 *       1. All functions shall have coresponding Unit tests
 *       2. These functions will make base for portable LM75A library (someday)
 */
#include "stdafx.h"

int HpLm75_RawTempToInt(int16_t rawTemp){
	if (rawTemp < 0){
		// negative values are weird :-O
		return (rawTemp+128) >> 8;
	} else {
		return rawTemp >> 8;
	}
}

void HpLm75_RawTempToStr(int16_t rawTemp,char *strOut, int strLen){

	rawTemp >>= 7; // now it is temperature * 2
	if (rawTemp < 0){
		// 0 from  "-0.5" can't have leading '-'
		sprintf_s(strOut,strLen,"-%d.%d", -rawTemp/2, -5*(rawTemp%2));
	} else {
		sprintf_s(strOut,strLen,"%d.%d", rawTemp/2, 5*(rawTemp%2));
	}
}