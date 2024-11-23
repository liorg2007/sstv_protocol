#pragma once

#include <stdint.h>

#define RED_CONST 0.299
#define GREEN_CONST 0.587
#define BLUE_COSNT 0.114 

struct RGBData {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};


class Pixel {
private:
	uint8_t _red;
	uint8_t _green;
	uint8_t _blue;

public:
	Pixel(uint8_t red, uint8_t green, uint8_t blue);
	RGBData GetRGB();
	uint8_t GetGrayScale();
};