//
// ch341-i2c-lm75a.cpp : Connecting LC CH341A USB Adapter to I2C Digital Temperature sensor LM75A
//

#include "stdafx.h"
// our local libraries
#include "hplm75.h"

// standard I2C Speed (100kHz)
#define HPCH_MODE_I2C_SPEED_STD 0x01
// MSB first on SPI
#define HPCH_MODE_SPI_MSB_FIRST 0x80

// LM75A has top 4-bit always 0x1001 = 0x90
#define HPCH_LM75A_ADDR_UPPER 0x90

// LM75 Pointer set to TEMP(erature)
#define HPCH_LM75A_POINTER_TEMP 0

#define HPCH_LM75A_TEMP_UNUSED_BITS 0x7f

int _tmain(int argc, _TCHAR* argv[])
{
	int    i    = 0;
	BOOL   ret  = EXIT_FAILURE;
	HANDLE h341 = NULL;
	ULONG iIndex = 0; // first device
	BYTE  i2cAddr = 0; 
	int16_t   tempRaw = 0;

	// write to I2C LM75A - set pointer register to TEMPerature
	BYTE  tempWrite[2] = { HPCH_LM75A_ADDR_UPPER | (i2cAddr << 1), HPCH_LM75A_POINTER_TEMP };
	// read I2C from LM75A - get back temperature
	BYTE  tempRead[2]  = { 0, 0 }; // input buffer to read temperature
	char  strTemp[16];

	printf("CH341 library version: %lu\n", CH341GetVersion());

	printf("Opening device# %lu\r\n", iIndex);
	h341 = CH341OpenDevice(iIndex);
	if (h341 == NULL){
		fprintf(stderr, "CH341OpenDevice(iDevIndex=%lu) failed\r\n", iIndex);
		goto exit0;
	}

	// NOTE: must be called *after* CH341OpenDevice()
	printf("CH341 driver  version: %lu\n", CH341GetDrvVersion());

	if(!CH341SetStream(iIndex,HPCH_MODE_I2C_SPEED_STD|HPCH_MODE_SPI_MSB_FIRST)){
		fprintf(stderr, "CH341SetStream(iDevIndex=%lu, iMode=0x%x) failed\r\n", iIndex, HPCH_MODE_I2C_SPEED_STD|HPCH_MODE_SPI_MSB_FIRST);
		goto exit1;
	}

	// read temperature
	if (!CH341StreamI2C(iIndex,sizeof(tempWrite),tempWrite,sizeof(tempRead),tempRead)){
		fprintf(stderr, "CH341StreamI2C(iDevIndex=%lu, ...) failed\r\n", iIndex);
		goto exit1;
	}

	tempRaw = (tempRead[1] & ~HPCH_LM75A_TEMP_UNUSED_BITS) | (tempRead[0] << 8);
	printf("tempRaw is %hd (0x%hx)\n",tempRaw,tempRaw);

	printf("Int Temp is %hd degrees of Celsius\n", HpLm75_RawTempToInt(tempRaw));

	HpLm75_RawTempToStr(tempRaw,strTemp,sizeof(strTemp));
	printf("Temp is %s degrees of Celsius\n", strTemp);

	ret = EXIT_SUCCESS;
exit1:
	CH341CloseDevice(iIndex);
exit0:
	return ret;
	return 0;
}

