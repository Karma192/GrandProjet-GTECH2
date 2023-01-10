#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include "Button.hpp"

class menuHUD
{
public:
	menuHUD();
	virtual ~menuHUD();
	void menuRender(sf::RenderWindow* win);
	void menuSelection(sf::RenderWindow* win);
	void menuTitle(sf::RenderWindow* win);
	void menuTxt();

private:
	float screenSizeX;
	float screenSizeY;

	sf::Texture menuBackground;
	sf::Sprite menuBckSprite;
	sf::RectangleShape selectionBck;
	sf::Vector2u oldScreenSize;
	sf::Font heartless;
	sf::Text title;
	sf::Text credit;
	sf::Text names;
	sf::RectangleShape playRect;
};

