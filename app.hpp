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

	int run() {
		if (!cap.isOpened()) {
			std::cerr << "Cannot open camera.\n";
			return -1;
		}
		while (true) {
			update();
			show();
			cv::waitKey(1);
		}
		return 0;
	}

private:
	void update() {
		cap.read(img);
		document_cropper.find_document(img);
		if (document_cropper.is_document_found()) {
			document_cropper.get_cropped_document(doc_img, doc_size);
			cv::cvtColor(doc_img, doc_img, cv::COLOR_BGR2GRAY);
		}
	}
	void show() const {
		cv::imshow("Image", img);
		if (document_cropper.is_document_found()) {
			cv::imshow("Document", doc_img);
		}
		if (should_show_prep) {
			document_cropper.show_preprocess();
		}

	}
};

App::App() : cap{ 0 }, doc_size{ int(cap.get(cv::CAP_PROP_FRAME_HEIGHT) / 1.41), cap.get(cv::CAP_PROP_FRAME_HEIGHT) }
{
}

App::~App()
{
}