#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include "scene/SceneManager.hpp"

class menuHUD
{
public:
	SceneManager sm;

	menuHUD();
	virtual ~menuHUD();
	void menuRender(sf::RenderWindow* win);
	void menuSelection(sf::RenderWindow* win);
	void menuTitle(sf::RenderWindow* win);
	void menuTxt(sf::RenderWindow* win);
	int detectedClick();

private:
	float screenSizeX = 0;
	float screenSizeY = 0;
	bool once = true;

	sf::Texture menuBackground;
	sf::Sprite menuBckSprite;
	sf::RectangleShape selectionBck;
	sf::Vector2u oldScreenSize;
	sf::Font heartless;
	sf::Text title;
	sf::Text credit;
	sf::Text names;
	sf::FloatRect titleBounds;
	sf::FloatRect playBounds;
	sf::RectangleShape playRect;
};

