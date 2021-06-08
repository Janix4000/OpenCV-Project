#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "app.hpp"

class Window
{
	sf::RenderWindow window;
	sf::Clock deltaClock;

	App app;


public:
	Window();
	~Window();
	int run();
protected:
	void user_update(const float dt);
	void user_render();
private:
	void full_update();
	void full_render();
};