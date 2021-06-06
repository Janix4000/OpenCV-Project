#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

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
	void update();
	void render();
private:
};