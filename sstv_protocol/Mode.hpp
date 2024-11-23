#pragma once

#include "Sound.hpp"
#include "Image.hpp"
#include <vector>

class Mode {
private:
	int _width;
	int _height;

public:
	Mode(int width, int height) :_width(width), _height(height) {}

	int getWidth() const { return _width; }
	int getHeight() const { return _height; }

	virtual std::vector<Sound> EncodeImage(const Image& image) = 0;
};