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
#include "document_via_color_preprocess.hpp"


cv::Mat imgOriginal, imgGray, imgBlur, imgCanny, imgThre, imgDil, imgErode, imgWarp, imgCrop;
int w = 420, h = 596;


int main() {
	cv::VideoCapture cap(0);
	cv::Mat img;
	cv::Mat doc_img;

	DocumentCropper<DocumentViaColorPreprocessor> document_cropper;
	//DocumentCropper<DocumentGrayScalePreprocessor> document_cropper;
	while (true) {
		cap.read(img);
		document_cropper.find_document(img);

		cv::imshow("Image", img);
		if (document_cropper.is_document_found()) {
			document_cropper.get_cropped_document(doc_img, { 600, 900 });
			cv::imshow("Document", doc_img);
		}
		document_cropper.show_preprocess();

		cv::waitKey(1);
	}
	return 0;
}