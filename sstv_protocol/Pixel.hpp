#pragma once

#define RED_CONST 0.299
#define GREEN_CONST 0.587
#define BLUE_COSNT 0.114 

struct RGBData {
	__int8 red;
	__int8 green;
	__int8 blue;
};


class Pixel {
private:
	__int8 _red;
	__int8 _green;
	__int8 _blue;

public:
	Pixel(__int8 red, __int8 green, __int8 blue);
	RGBData GetRGB();
	__int8 GetGrayScale();
};