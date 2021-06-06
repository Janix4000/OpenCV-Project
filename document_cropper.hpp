#pragma once

#include <array>

#include "document_corners_finder.hpp"
#include "document_gray_scale_preprocessor.hpp"


template <typename Preprocessor>
class DocumentCropper {
	static constexpr size_t max_no_found_tries = 8;
	static constexpr int default_width = 420;
	static constexpr int default_height = 600;

	DocumentCornersFinder<Preprocessor> corner_finder;
	Points corners;
	size_t failed_tries = 0;
	cv::Mat img;

public:


	bool find_document(const cv::Mat& src) {
		const auto contours = corner_finder.get_document_corners(src);
		if (contours.empty()) {
			img = src;
			failed_tries++;
			return false;
		}
		else {
			corners = contours;
			failed_tries = 0;
			return true;
		}
		//drawPoints(initialPoints, Scalar(0, 0, 255));
		//docPoints = get_reordered(initialPoints);
		//draw_points(src, docPoints, Scalar(0, 255, 0));

	}

	bool is_document_found() const {
		return failed_tries < max_no_found_tries && !corners.empty();
	}

	bool get_cropped_document(cv::Mat& dst, cv::Size desired_size = { default_height, default_width }) const {
		if (is_document_found()) {
			auto warp_img = get_warp(desired_size.width, desired_size.height);
			int cropVal = 0;
			const cv::Rect roi = { cropVal, cropVal, desired_size.width - cropVal * 2, desired_size.height - cropVal * 2 };
			dst = warp_img(roi);
			return true;
		}
		else {
			dst = cv::Mat(desired_size.width, desired_size.height, CV_8SC3, cv::Scalar());
			return false;
		}
	}

	void show_preprocess() const {
		corner_finder.show_preprocess();
	}

private:

	cv::Mat get_warp(int w, int h) const
	{
		std::array<cv::Point2f, 4> src = { corners[0], corners[1], corners[3], corners[2] };
		//std::copy(corners.begin(), corners.begin() + 4, src.begin());

		std::array<cv::Point2f, 4> dst = { cv::Point2f{0.0f, 0.0f}, {(float)w, 0.0f}, {0.0f, (float)h}, {(float)w, (float)h} };

		auto matrix = cv::getPerspectiveTransform(src, dst);
		cv::Mat img_warp;
		cv::warpPerspective(img, img_warp, matrix, cv::Point(w, h));
		return img_warp;
	}

};

