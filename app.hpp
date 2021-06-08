#pragma once

#pragma warning(push, 0)        
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#pragma warning(pop)

#include <iostream>

#include "document_cropper.hpp"
#include "document_via_color_preprocess.hpp"



class App
{
	cv::VideoCapture cap;
	const cv::Size doc_size;
	cv::Mat img;
	cv::Mat doc_img;
	DocumentCropper<DocumentViaColorPreprocessor> document_cropper;
	bool should_show_prep = true;

public:
	App();
	~App();

	int run();


	void update();
	void show() const;
	cv::Mat get_document_img() const;
	cv::Mat get_img() const { return img; }
};

