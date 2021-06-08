#include "window.hpp"


#include <SFML/Window/Event.hpp>

#include "imgui.h" // necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h
#include "imgui-SFML.h" // for ImGui::SFML::* functions and SFML-specific overloads


Window::Window() : window(sf::VideoMode(1280, 720), "ImGui + SFML = <3")
{
	window.setFramerateLimit(60);
	ImGui::SFML::Init(window);
}

Window::~Window()
{
	ImGui::SFML::Shutdown();
}

int Window::run()
{
	while (window.isOpen()) {
		full_update();
		full_render();
	}
	return 0;
}

void Window::full_update()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		ImGui::SFML::ProcessEvent(event);

		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}

	const auto dt = deltaClock.restart();

	user_update(dt.asSeconds());

	ImGui::SFML::Update(window, dt);
}

void Window::full_render()
{
	ImGui::Begin("Hello, world!");

	user_render();

	ImGui::End();
	window.clear();
	ImGui::SFML::Render(window);
	window.display();
}



void Window::user_update(const float dt)
{
	app.update();
}

void Window::user_render()
{
	img = app.get_img();
	if (!img.empty()) {
		cv::cvtColor(img, imgRGBA, cv::COLOR_BGR2RGBA);
		image.create(imgRGBA.cols, imgRGBA.rows, imgRGBA.ptr());
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		ImGui::Image(sprite);
	}
}