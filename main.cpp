#pragma warning(push, 0)        
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//#include <opencv2/tracking.hpp>
#pragma warning(pop)

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace cv;
//using namespace std;

/////////////// Project 2 - Document Scanner //////////////////////

using Points = std::vector<cv::Point>;

cv::Mat imgOriginal, imgGray, imgBlur, imgCanny, imgThre, imgDil, imgErode, imgWarp, imgCrop;
Points initialPoints, docPoints;
int w = 420, h = 596;

cv::Mat preprocess_img(const cv::Mat& img)
{
	cv::Mat res;
	cv::cvtColor(img, imgGray, COLOR_BGR2GRAY);
	cv::GaussianBlur(imgGray, imgBlur, cv::Size(3, 3), 3, 0);
	cv::Canny(imgBlur, imgCanny, 25, 75);
	const auto kernel = cv::getStructuringElement(MORPH_RECT, cv::Size(3, 3));
	cv::dilate(imgCanny, imgDil, kernel);
	//erode(imgDil, imgErode, kernel);
	return imgDil;
}

Points getContours(const cv::Mat& image) {

	std::vector<Points> contours;
	std::vector<Vec4i> hierarchy;

	cv::findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	Points biggest;
	int maxArea = 0;
	for (const auto& contour : contours)
	{
		const auto area = static_cast<int>(contourArea(contour));
		if (area > 1000)
		{
			const auto peri = arcLength(contour, true);
			Points conPoly;
			approxPolyDP(contour, conPoly, 0.02 * peri, true);

			if (area > maxArea && conPoly.size() == 4) {
				biggest = conPoly;
				maxArea = area;
			}
		}
	}
	return biggest;
}

void draw_points(cv::Mat& dst, const Points& points, Scalar color)
{
	size_t i = 0;
	for (auto& point : points)
	{
		circle(dst, point, 10, color, FILLED);
		putText(dst, std::to_string(i), point, FONT_HERSHEY_PLAIN, 4, color, 4);
		i++;
	}
	const std::vector<Points> contours = { points };
	drawContours(dst, contours, -1, color, 2);
}

Points get_reordered(const Points& points)
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

cv::Mat get_warp(const cv::Mat& img, const Points& points, float w, float h)
{
	std::array<Point2f, 4> src;
	std::copy(points.begin(), points.begin() + 4, src.begin());

	std::array<Point2f, 4> dst = { Point2f{0.0f, 0.0f}, Point2f{w, 0.0f}, Point2f{0.0f, h}, Point2f{w, h} };

	auto matrix = cv::getPerspectiveTransform(src, dst);
	cv::warpPerspective(img, imgWarp, matrix, cv::Point(w, h));
	return imgWarp;
}

bool get_document_img(cv::Mat& src, cv::Mat& dst, cv::Size desired_size = {w, h}) {
	imgThre = preprocess_img(src);

	initialPoints = getContours(imgThre);
	if (initialPoints.size() < 4) {
		return false;
	}
	//drawPoints(initialPoints, Scalar(0, 0, 255));
	docPoints = get_reordered(initialPoints);
	draw_points(src, docPoints, Scalar(0, 255, 0));

	imgWarp = get_warp(src, docPoints, desired_size.width, desired_size.height);

	//Crop - Step 4
	int cropVal = 5;
	const cv::Rect roi = { cropVal, cropVal, w - cropVal * 2, h - cropVal * 2 };
	dst = imgWarp(roi);
	return true;
}

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

	while (true) {

		cap.read(img);
		cv::Mat document_img;
		const auto found_doc = get_document_img(img, document_img);

		cv::imshow("Image", img);
		if (found_doc) {
			cv::imshow("Image Dilation", imgThre);
			cv::imshow("Image Warp", imgWarp);
			cv::imshow("Documet", document_img);
		}
		

		cv::waitKey(1);
	}

	return 0;
}