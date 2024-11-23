#include "Image.hpp"

Image::Image(const std::string& path)
	:_image(cv::imread(path))
{
  _width = _image.cols;
  _height = _image.rows;
  _channels = _image.channels();
}

cv::Mat Image::resize(const cv::Mat& inImage, int width, int height)
{
  cv::Mat outImage;
  cv::resize(inImage, outImage, cv::Size(width, height));

  return outImage;
}

std::vector<uchar> Image::getPixelsGray() const
{
  cv::Mat grayImage;
  cv::cvtColor(_image, grayImage, cv::COLOR_BGR2GRAY);

  std::vector<uchar> pixels(_width * _height);
  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      pixels[i * _width + j] = grayImage.at<uchar>(i, j);
    }
  }
  return pixels;
}

std::vector<uchar> Image::getPixelsGray(int width, int height) const
{
  cv::Mat grayImage;
  cv::Mat resized;
  cv::cvtColor(_image, grayImage, cv::COLOR_BGR2GRAY);

  resized = resize(grayImage, width, height);

  std::vector<uchar> pixels(width * height);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      pixels[i * width + j] = resized.at<uchar>(i, j);
    }
  }
  return pixels;
}

std::vector<cv::Vec3b> Image::getPixelsColor() const
{
  if (_channels != 3) {
    throw std::runtime_error("Image is not a 3-channel color image");
  }

  std::vector<cv::Vec3b> pixels(_width * _height);
  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      pixels[i * _width + j] = _image.at<cv::Vec3b>(i, j);
    }
  }
  return pixels;
}

std::vector<cv::Vec3b> Image::getPixelsColor(int width, int height) const
{
  cv::Mat resized;
  if (_channels != 3) {
    throw std::runtime_error("Image is not a 3-channel color image");
  }

  resized = resize(_image, width, height);

  std::vector<cv::Vec3b> pixels(width * height);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      pixels[i * width + j] = resized.at<cv::Vec3b>(i, j);
    }
  }
  return pixels;
}



