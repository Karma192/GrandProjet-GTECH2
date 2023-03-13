#include "Doors.hpp"

Doors::Doors()
{
	exit.setSize(sf::Vector2f(30.f, 30.f));
	exit.setFillColor(sf::Color::White);
	exit.setPosition(sf::Vector2f(250, 250));
}

Doors::~Doors()
{
}

void Doors::Loop()
{
}

void Doors::Render()
{
	gameData = GetGameData();
	gameData.window->draw(exit);
}
