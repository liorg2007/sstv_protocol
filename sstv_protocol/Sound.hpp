#pragma once

#include <Windows.h>

class Sound {
private:
	int _frequency;
	double _duration;

public:
	Sound(int frequency, double duration);
	void Play() const;
};