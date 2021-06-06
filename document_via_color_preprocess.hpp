#pragma once
#pragma once
#pragma warning(push, 0)        
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//#include <opencv2/tracking.hpp>
#pragma warning(pop)

#include "document_preprocesor.hpp"


class DocumentViaColorPreprocessor : public DocumentPreprocessor {
	cv::Mat img_mask, img_dil;
	static constexpr int hmin = 0, smin = 0, vmin = 100;
	static constexpr int hmax = 179, smax = 70, vmax = 255;
public:
	void get_preprocessed(const cv::Mat& src, cv::Mat& dst) override
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
	void show_preprocess() const override {
		cv::imshow("Image Mask", img_mask);
		cv::imshow("Image Dilation", img_dil);
	}
};