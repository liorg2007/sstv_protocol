#include "Pixel.hpp"

Pixel::Pixel(uint8_t red, uint8_t green, uint8_t blue)
	:_red(red), _green(green), _blue(blue)
{
}

RGBData Pixel::GetRGB()
{
	return RGBData{_red, _green, _blue};
}

uint8_t Pixel::GetGrayScale()
{
	return _red * RED_CONST + _green * GREEN_CONST + _blue * BLUE_COSNT;
}