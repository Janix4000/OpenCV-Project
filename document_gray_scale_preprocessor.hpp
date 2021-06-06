#pragma once
#include "document_preprocesor.hpp"

class DocumentGrayScalePreprocessor : public DocumentPreprocessor {
	cv::Mat img_gray, img_blur, img_dil, img_canny;
public:

	void get_preprocessed(const cv::Mat& src, cv::Mat& dst) override;
	void show_preprocess() const override;
};