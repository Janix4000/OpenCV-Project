#pragma once
#pragma warning(push, 0)        
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//#include <opencv2/tracking.hpp>
#pragma warning(pop)

#include "document_preprocesor.hpp"

class DocumentGrayScalePreprocessor : public DocumentPreprocessor {
	cv::Mat img_gray, img_blur, img_dil, img_canny;
public:
	cv::Mat get_preprocessed(const cv::Mat& src) override
	{
		cv::Mat res;
		cv::cvtColor(src, img_gray, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(img_gray, img_blur, cv::Size(3, 3), 3, 0);
		cv::Canny(img_blur, img_canny, 25, 75);
		const auto kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
		cv::dilate(img_canny, img_dil, kernel);
		//erode(imgDil, imgErode, kernel);
		res = img_dil;
		return res;
	}
	void show_preprocess() const override {
		cv::imshow("Image Dilation", img_dil);
	}
};