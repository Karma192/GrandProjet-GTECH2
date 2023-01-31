#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include<cstdlib>
#include "GameObject.hpp"

class Object : public GameObject
{
public:
	Object();
	~Object();

	void RandomObject(sf::RenderWindow* win);

private:
	int windowWidth;
	int windowHeight;
	int randomX;
	int randomY;
	bool once;
	sf::RectangleShape randomPosObject;
	sf::RenderWindow* win;
};

