#ifndef Bmp085_h
#define Bmp085_h
#include <Arduino.h>

#define Bmp085_ADDR					0x77
#define BUFFER_SIZE					3
#define AUTO_UPDATE_TEMPERATURE		true
#define CAL_AC1		 				0xAA
#define CAL_AC2		 				0xAC
#define CAL_AC3		 				0xAE
#define CAL_AC4		 				0xB0
#define CAL_AC5		 				0xB2
#define CAL_AC6		 				0xB4
#define CAL_B1						0xB6
#define CAL_B2						0xB8
#define CAL_MB						0xBA
#define CAL_MC						0xBC
#define CAL_MD						0xBE
#define CONTROL		 				0xF4
#define CONTROL_OUTPUT				0xF6
#define SOFTRESET					0xE0
#define VERSION		 				0xD1
#define CHIPID						0xD0
#define MODE_ULTRA_LOW_POWER		0
#define MODE_STANDARD		 		1
#define MODE_HIGHRES				2
#define MODE_ULTRA_HIGHRES	 		3
#define READ_TEMPERATURE		 	0x2E
#define READ_PRESSURE		 		0x34
#define MSLP						101325

class Bmp085
{
public:
	Bmp085();
	void init();
	void init(byte _BMPMode, int32_t _initVal, bool _centimeters);
	byte getDevAddr();
	byte getMode();
	void setMode(byte _BMPMode);
	void setLocalPressure(int32_t _Pa);
	void setLocalAbsAlt(int32_t _centimeters);
	void setAltOffset(int32_t _centimeters);
	void sethPaOffset(int32_t _Pa);
	void zeroCal(int32_t _Pa, int32_t _centimeters);
	void getPressure(int32_t * _Pa);
	void getAltitude(int32_t * _centimeters);
	void getTemperature(int32_t * _Temperature);
	void calcTrueTemperature();
	void calcTruePressure(long * _TruePressure);
	 void dumpCalData();
	void writemem(uint8_t _addr, uint8_t _val);
	void readmem(uint8_t _addr, uint8_t _nbytes, uint8_t __buff[]);
	private:
	int ac1, ac2, ac3, b1, b2, mb, mc, md;
	unsigned int ac4, ac5, ac6;
	long b5, oldEMA;
	uint8_t _dev_address;
	byte _buff[BUFFER_SIZE];
	int _oss;
	int _pressure_waittime[4];
	int32_t _cm_Offset, _Pa_Offset;
	int32_t _param_datum, _param_centimeters;
	void getCalData();
};
#endif
