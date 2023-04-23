#pragma once 

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <vector>
#include "GameObject.hpp"
//#include "scene/SceneManager.hpp"

class menuHUD : public GameObject
{
public:
	//SceneManager sm;

	menuHUD();
	virtual ~menuHUD();

	virtual void Loop()override;
	virtual void Render()override;

private:
	bool optionOn = true;

	float screenSizeX = 0;
	float screenSizeY = 0;
	int i = 0;
	float newVol = 100;

	sf::Texture menuBackground;
	sf::Sprite menuBckSprite;
	sf::RectangleShape selectionBck;
	sf::Vector2u oldScreenSize;
	sf::Font heartless;
	sf::Font Antique;
	sf::Text title;
	sf::Text screenTxt;
	sf::Text volumeTxt;
	sf::Text volumeTxtValue;
	sf::Text playFirstChoice;
	sf::Text options;
	sf::Text languageTxt;

	sf::RectangleShape languageOptionEN;
	sf::RectangleShape languageOptionFR;
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

	void menuSelection();
	void menuTitle();
	void menuTxt();
	bool detectedClick();
	void Volume();
	void GoBack();
	void ChangeResolution();
	void Language();
};