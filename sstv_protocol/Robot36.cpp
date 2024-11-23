#include "Robot36.hpp"


Robot36::Robot36()
  :Mode(240, 320), LeaderSound(1200, 300), VerticalSync(1900, 88.88), HorizontalSync(1200, 4.862)
{

}

std::vector<Sound> Robot36::EncodeImage(const Image& image)
{
  std::vector<cv::Vec3b> pixels = image.getPixelsColor(getWidth(), getHeight());
  std::vector<Sound> sounds;
  
  sounds.push_back(LeaderSound);

  for (int i = 0; i < 9; ++i)
    sounds.push_back(VerticalSync);

  // B - [0] G - [1] R - [2]
  for (const auto& pixel : pixels) {
    sounds.push_back(HorizontalSync);
    sounds.emplace_back(1500 + ((pixel[0] / 255) * (2300 - 1500)), 29.63);
    sounds.emplace_back(1500 + ((pixel[1] / 255) * (2300 - 1500)), 29.63);
    sounds.emplace_back(1500 + ((pixel[2] / 255) * (2300 - 1500)), 29.63);
  }

  return sounds;
}
