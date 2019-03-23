// hplm75-tests.cpp : Tests for hplm75.h/.cpp library
//

#include "stdafx.h"

// we use such weird path to avoid conflich of two stdafx.h headers (each project have one)
#include "../ch341-i2c-lm75a/hplm75.h"

GREATEST_MAIN_DEFS();

TEST test_HpLm75_RawTempToInt(void) {

	// we pass 0 with "undefined bits" set to 1 - to verify that they do not affect results
	int r = HpLm75_RawTempToInt( (int16_t)0x7f );
	ASSERT_EQ_FMT(0, r, "%d");
	r = HpLm75_RawTempToInt( (int16_t)0x80 ); // 0.5
	ASSERT_EQ_FMT(0, r, "%d");
	r = HpLm75_RawTempToInt( (int16_t)0x100 ); // 1.0
	ASSERT_EQ_FMT(1, r, "%d");
	r = HpLm75_RawTempToInt( (int16_t)0x180 ); // 1.5
	ASSERT_EQ_FMT(1, r, "%d");
	r = HpLm75_RawTempToInt( (int16_t)0xff00 ); // -1
	ASSERT_EQ_FMT(-1, r, "%d");
	r = HpLm75_RawTempToInt( (int16_t)0xffff ); // -0.5
	ASSERT_EQ_FMT(0, r, "%d");
	r = HpLm75_RawTempToInt( (int16_t) (20 << 7) ); // 10.0
	ASSERT_EQ_FMT(10, r, "%d");
	r = HpLm75_RawTempToInt( (int16_t) (21 << 7) ); // 10.5
	ASSERT_EQ_FMT(10, r, "%d");
	r = HpLm75_RawTempToInt( (int16_t)(-20 << 7) ); // -10
	ASSERT_EQ_FMT(-10, r, "%d");
	r = HpLm75_RawTempToInt( (int16_t)(-19 << 7) ); // -9.5
	ASSERT_EQ_FMT(-9, r, "%d");

} 

TEST test_HpLm75_HpLm75_RawTempToStr(void) {
	char str[16];
	HpLm75_RawTempToStr( (int16_t) (0x7f), str, sizeof(str) ); // 0.5
	ASSERT_STR_EQ("0.0",str);
	HpLm75_RawTempToStr( (int16_t) (1 << 7), str, sizeof(str) ); // 0.5
	ASSERT_STR_EQ("0.5",str);
	HpLm75_RawTempToStr( (int16_t) (2 << 7), str, sizeof(str) ); // 1.0
	ASSERT_STR_EQ("1.0",str);
	HpLm75_RawTempToStr( (int16_t) (3 << 7), str, sizeof(str) ); // 1.5
	ASSERT_STR_EQ("1.5",str);
	HpLm75_RawTempToStr( (int16_t) (-1 << 7), str, sizeof(str) ); // -0.5
	ASSERT_STR_EQ("-0.5",str);
	HpLm75_RawTempToStr( (int16_t) (-2 << 7), str, sizeof(str) ); // -1.0
	ASSERT_STR_EQ("-1.0",str);
	HpLm75_RawTempToStr( (int16_t) (-3 << 7), str, sizeof(str) ); // -1.5
	ASSERT_STR_EQ("-1.5",str);
	HpLm75_RawTempToStr( (int16_t) (-4 << 7), str, sizeof(str) ); // -2.0
	ASSERT_STR_EQ("-2.0",str);


}

int _tmain(int argc, _TCHAR* argv[])
{
	GREATEST_MAIN_BEGIN();
    RUN_TEST(test_HpLm75_RawTempToInt);
    RUN_TEST(test_HpLm75_HpLm75_RawTempToStr);
	GREATEST_MAIN_END();        /* display results */ 
}

