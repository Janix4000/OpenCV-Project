#include "window.hpp"


#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
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
		update();
		render();
	}
	return 0;
}

void Window::update()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		ImGui::SFML::ProcessEvent(event);

		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}

	const auto dt = deltaClock.restart();

	app.update();

	ImGui::SFML::Update(window, dt);
}

void Window::render()
{
	ImGui::Begin("Hello, world!");

	// render
	const auto& img = app.get_document_img();
	sf::Image image;
	image.create(img.cols, img.rows, img.ptr());
	sf::Texture texture;
	texture.loadFromImage(image);
	sf::Sprite sprite;
	sprite.setTexture(texture);


	ImGui::Image(sprite);

	ImGui::End();

	window.clear();
	ImGui::SFML::Render(window);
	window.display();
}
