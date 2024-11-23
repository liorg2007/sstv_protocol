#pragma once

#include "Mode.hpp"

class Robot36 : public Mode {
private:
	const Sound LeaderSound;
	const Sound VerticalSync;
	const Sound HorizontalSync;

public:
	Robot36();
	std::vector<Sound> EncodeImage(const Image& image) override;
};