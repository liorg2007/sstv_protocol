#include "Sound.hpp"

Sound::Sound(int frequency, double duration)
	:_frequency(frequency), _duration(duration)
{
}

void Sound::Play() const
{
	Beep(_frequency, _duration);
}


