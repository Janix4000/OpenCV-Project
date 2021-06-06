#pragma once

#pragma warning(push, 0)        
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//#include <opencv2/tracking.hpp>
#pragma warning(pop)

class DocumentPreprocessor {
public:
	virtual cv::Mat get_preprocessed(const cv::Mat& src) = 0;
	virtual void show_preprocess() const = 0;
};