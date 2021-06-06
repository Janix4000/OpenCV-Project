#include "document_gray_scale_preprocessor.hpp"

void DocumentGrayScalePreprocessor::get_preprocessed(const cv::Mat& src, cv::Mat& dst)
{
	cv::cvtColor(src, img_gray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(img_gray, img_blur, cv::Size(3, 3), 3, 0);
	cv::Canny(img_blur, img_canny, 25, 75);
	const auto kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::dilate(img_canny, img_dil, kernel);
	//erode(imgDil, imgErode, kernel);
	dst = img_dil;
}

void DocumentGrayScalePreprocessor::show_preprocess() const
{
	cv::imshow("Image Dilation", img_dil);
}
