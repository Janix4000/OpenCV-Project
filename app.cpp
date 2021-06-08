#include "app.hpp"

int App::run()
{
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

void App::update()
{
	cap.read(img);
	document_cropper.find_document(img);
	if (document_cropper.is_document_found()) {
		document_cropper.get_cropped_document(doc_img, doc_size);
		cv::cvtColor(doc_img, doc_img, cv::COLOR_BGR2GRAY);
	}
}

void App::show() const
{
	cv::imshow("Image", img);
	if (document_cropper.is_document_found()) {
		cv::imshow("Document", doc_img);
	}
	if (should_show_prep) {
		document_cropper.show_preprocess();
	}
}



App::App() : cap{ 0 },
doc_size{ int(cap.get(cv::CAP_PROP_FRAME_HEIGHT) / 1.41), cap.get(cv::CAP_PROP_FRAME_HEIGHT) },
doc_img(doc_size.width, doc_size.height, CV_8UC3, cv::Scalar())
{
}

App::~App()
{
}

cv::Mat App::get_document_img() const
{
	return doc_img;
}
