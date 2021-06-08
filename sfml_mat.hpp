//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>


#pragma once
class SFML_Mat
{
	cv::Mat mat;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	SFML_Mat(const cv::Mat& mat) {
		set_mat(mat);
	}

	void set_mat(const cv::Mat& _mat) {
		mat = _mat.clone();
		cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);
		image.create(mat.cols, mat.rows, mat.ptr());
		texture.loadFromImage(image);
		sprite.setTexture(texture);
	}

	operator sf::Sprite() const {
		return sprite;
	}

	operator cv::Mat& () {
		return mat;
	}
};

