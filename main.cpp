#pragma warning(push, 0)        
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//#include <opencv2/tracking.hpp>
#pragma warning(pop)

#include <iostream>
#include <algorithm>
#include <iterator>

#include "document_cropper.hpp"


cv::Mat imgOriginal, imgGray, imgBlur, imgCanny, imgThre, imgDil, imgErode, imgWarp, imgCrop;
int w = 420, h = 596;


int main() {

	//const std::string path = "Resources/paper.jpg";
	//imgOriginal = cv::imread(path);
	//const auto r = cv::selectROI("Select region of interest", imgOriginal);
	//const auto desired_img = imgOriginal(r);
	

	//cv::imshow("Image", desired_img);
	////imshow("Image Dilation", imgThre);
	////imshow("Image Warp", imgWarp);
	//cv::imshow("Image Crop", imgCrop);
	//cv::waitKey(0);


	cv::VideoCapture cap(0);
	cv::Mat img;
	DocumentCropper document_cropper;

	while (true) {

		cap.read(img);
		cv::Mat doc_img;

		cv::imshow("Image", img);
		document_cropper.find_document(img);
		if (document_cropper.is_document_found()) {
			doc_img = document_cropper.get_cropped_document();
			cv::imshow("Document", doc_img);
			document_cropper.show_preprocess();
		}
		cv::waitKey(1);
	}

	return 0;
}