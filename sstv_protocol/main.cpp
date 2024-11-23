#include "Robot36.hpp"

int main() {
	Image img("C:\\Users\\User\\Pictures\\Shuit.jpeg");
	auto sounds = Robot36().EncodeImage(img);

	for (auto sound : sounds)
		sound.Play();


}