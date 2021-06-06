#include "document_via_color_preprocess.hpp"

void DocumentViaColorPreprocessor::get_preprocessed(const cv::Mat& src, cv::Mat& dst)
{
	GaussianBlur(src, img_mask, cv::Size(9, 9), 3, 0);
	cvtColor(img_mask, img_mask, cv::COLOR_BGR2HSV);

	static const cv::Scalar lower(hmin, smin, vmin);
	static const cv::Scalar upper(hmax, smax, vmax);
	inRange(img_mask, lower, upper, img_mask);

	Canny(img_mask, img_dil, 25, 75);
	const auto kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	dilate(img_dil, img_dil, kernel);
	dst = img_dil;
}

void DocumentViaColorPreprocessor::show_preprocess() const
{
	cv::imshow("Image Mask", img_mask);
	cv::imshow("Image Dilation", img_dil);
}
