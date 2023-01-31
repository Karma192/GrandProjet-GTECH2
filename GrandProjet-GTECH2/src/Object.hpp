#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <cstdlib>
#include "GameObject.hpp"
#include "Player.hpp"

class Object : public GameObject
{
public:
	Object();
	~Object();

	void RandomObject(sf::RenderWindow* win);
	sf::RectangleShape randomPosObject;

	int randomX;
	int randomY;

private:
	sf::RenderWindow* win;
};

