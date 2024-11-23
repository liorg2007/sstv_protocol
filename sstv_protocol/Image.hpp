#pragma once

#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

class Image {
private:
	cv::Mat _image;
	int _width;
	int _height;
	int _channels;

public:
	Image(const std::string& path);

	static cv::Mat resize(const cv::Mat& inImage, int width, int height);

	std::vector<uchar> getPixelsGray() const;
	std::vector<uchar> getPixelsGray(int width, int height) const;

	std::vector<cv::Vec3b> getPixelsColor() const;
	std::vector<cv::Vec3b> getPixelsColor(int width, int height) const;
};