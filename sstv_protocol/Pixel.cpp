#include "Pixel.hpp"

Pixel::Pixel(__int8 red, __int8 green, __int8 blue)
	:_red(red), _green(green), _blue(blue)
{
}

RGBData Pixel::GetRGB()
{
	return RGBData{_red, _green, _blue};
}

__int8 Pixel::GetGrayScale()
{
	return _red * RED_CONST + _green * GREEN_CONST + _blue * BLUE_COSNT;
}