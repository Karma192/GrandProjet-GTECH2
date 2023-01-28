#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <vector>
//#include "scene/SceneManager.hpp"

class menuHUD
{
public:
	//SceneManager sm;

	menuHUD();
	virtual ~menuHUD();
	void menuRender(sf::RenderWindow* win);
	void menuSelection(sf::RenderWindow* win);
	void menuTitle(sf::RenderWindow* win);
	void menuTxt(sf::RenderWindow* win);
	bool detectedClick();
	void Volume(sf::RenderWindow* win);
	void GoBack(sf::RenderWindow* win);
	void ChangeResolution(sf::RenderWindow* win);
	bool once = true;

private:
	float screenSizeX = 0;
	float screenSizeY = 0;
	int i = 0;

	sf::Texture menuBackground;
	sf::Sprite menuBckSprite;
	sf::RectangleShape selectionBck;
	sf::Vector2u oldScreenSize;
	sf::Font heartless;
	sf::Text title;
	sf::Text screenTxt;
	sf::Text playFirstChoice;
	sf::Text options;
	sf::FloatRect titleBounds;
	sf::FloatRect playBounds;
	sf::FloatRect returnGlobalPos;
	sf::FloatRect buttonChangeRect;
	sf::RectangleShape playRect;
	sf::RectangleShape returnbutton;
	sf::RectangleShape screenResLow;
	sf::Font font;
	std::vector <sf::Text> play;
	sf::RectangleShape volume;
	sf::Vector2i mousePos;
};

