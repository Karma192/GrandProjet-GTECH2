#include "Object.hpp"

Object::Object()
{
	randomX = rand();
	randomY = rand();
	randomPosObject.setSize(sf::Vector2f(5, 5));
	randomPosObject.setFillColor(sf::Color::Green);
	randomPosObject.setPosition(randomX % 1920 - 5, randomY % 1080 -5);

	randomX = rand();
	randomY = rand();
	randomPosObject2.setSize(sf::Vector2f(5, 5));
	randomPosObject2.setFillColor(sf::Color::Magenta);
	randomPosObject2.setPosition(randomX % 1920 - 5, randomY % 1080 - 5);
}

Object::~Object()
{
}

void Object::Loop()
{

}

void Object::Render()
{
	gameData = GetGameData();
	gameData.window->draw(randomPosObject);
	gameData.window->draw(randomPosObject2);
}