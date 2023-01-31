#include "Object.hpp"

Object::Object()
{
	randomX = rand();
	randomY = rand();
}

Object::~Object()
{
}

void Object::RandomObject(sf::RenderWindow* win)
{

	windowWidth = win->getSize().x;
	windowHeight = win->getSize().y;
	int resultX = randomX % windowWidth - 5;
	int resultY = randomY % windowHeight - 5;
	randomPosObject.setSize(sf::Vector2f(5, 5));
	randomPosObject.setFillColor(sf::Color::Green);
	randomPosObject.setPosition(resultX, resultY);
	win->draw(randomPosObject);
}
