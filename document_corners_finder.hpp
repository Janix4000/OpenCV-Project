#pragma once

#pragma warning(push, 0)        
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//#include <opencv2/tracking.hpp>
#pragma warning(pop)

#include <vector>
#include <algorithm>
#include <memory>

#include "document_preprocesor.hpp"

using Points = std::vector<cv::Point>;

template <typename Preprocessor>
class DocumentCornersFinder {
	Preprocessor preprocessor;
	mutable cv::Mat img;
	cv::Mat preprocessed_img;
	Points prev_corners;

public:
	static constexpr float min_area_ratio = 0.25f;

	Points get_document_corners(const cv::Mat& src);

	void show_preprocess(const bool show_sub = true) const;

private:


	Points get_contours(const cv::Mat& image);

	void draw_points(cv::Scalar color) const;

	Points get_reordered(const Points& points);
};

template <typename Preprocessor>
Points DocumentCornersFinder<Preprocessor>::get_reordered(const Points& points)
{
	Points new_points;
	std::vector<int> sum_points, sub_points;
	transform(points.begin(), points.end(), back_inserter(sum_points), [](auto& point) {
		return point.x + point.y;
		});
	transform(points.begin(), points.end(), back_inserter(sub_points), [](auto& point) {
		return point.x - point.y;
		});

	const size_t i_min_sum = std::distance(sum_points.begin(), std::min_element(sum_points.begin(), sum_points.end()));
	const size_t i_max_sub = std::distance(sub_points.begin(), std::max_element(sub_points.begin(), sub_points.end()));
	const size_t i_min_sub = std::distance(sub_points.begin(), std::min_element(sub_points.begin(), sub_points.end()));
	const size_t i_max_sum = std::distance(sum_points.begin(), std::max_element(sum_points.begin(), sum_points.end()));

	new_points.push_back(points[i_min_sum]); //0
	new_points.push_back(points[i_max_sub]); //1
	new_points.push_back(points[i_max_sum]); //2
	new_points.push_back(points[i_min_sub]); //3

	return new_points;
}

template <typename Preprocessor>
void DocumentCornersFinder<Preprocessor>::draw_points(cv::Scalar color) const
{
	size_t i = 0;
	for (auto& point : prev_corners)
	{
		circle(img, point, 10, color, cv::FILLED);
		putText(img, std::to_string(i), point, cv::FONT_HERSHEY_PLAIN, 4, color, 4);
		i++;
	}
	const std::vector<Points> contours = { prev_corners };
	drawContours(img, contours, -1, color, 2);
}

template <typename Preprocessor>
Points DocumentCornersFinder<Preprocessor>::get_contours(const cv::Mat& image)
{
	std::vector<Points> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::findContours(image, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	const auto min_area = static_cast<int>(image.rows * image.cols * min_area_ratio);

	Points biggest;
	int maxArea = 0;
	for (const auto& contour : contours)
	{
		const auto area = static_cast<int>(cv::contourArea(contour));
		if (area > min_area)
		{
			const auto peri = arcLength(contour, true);
			Points conPoly;
			approxPolyDP(contour, conPoly, 0.05 * peri, true);

			if (area > maxArea && conPoly.size() == 4) {
				biggest = conPoly;
				maxArea = area;
			}
		}
	}
	return biggest;
}

template <typename Preprocessor>
void DocumentCornersFinder<Preprocessor>::show_preprocess(const bool show_sub /*= true*/) const
{
	if (prev_corners.size() > 0) {
		draw_points({ 255, 0, 0 });
		cv::imshow("Corners", img);
	}
	if (show_sub) {
		preprocessor.show_preprocess();
	}
}

template <typename Preprocessor>
Points DocumentCornersFinder<Preprocessor>::get_document_corners(const cv::Mat& src)
{
	preprocessor.get_preprocessed(src, preprocessed_img);
	const auto initial_points = get_contours(preprocessed_img);
	if (initial_points.empty()) {
		return {};
	}
	const auto corners = get_reordered(initial_points);

	prev_corners = corners;
	src.copyTo(img);

	return corners;
}
