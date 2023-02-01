#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <vector>
//#include "scene/SceneManager.hpp"
#include "GameObject.hpp"

class menuHUD : public GameObject
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
	void Language(sf::RenderWindow* win);
	bool once = true;

  virtual void Loop()override;
  virtual void Render()override;

  void menuSelection();
  void menuTitle();
  void menuTxt();
  
private:
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
};