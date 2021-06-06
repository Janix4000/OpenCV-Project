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
	void get_preprocessed(const cv::Mat& src, cv::Mat& dst) override;
	void show_preprocess() const override;
};