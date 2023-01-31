#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include "GameObject.hpp"

class menuHUD : public GameObject
{
public:
    menuHUD();
    virtual ~menuHUD();

    virtual void Loop()override;
    virtual void Render()override;

    void menuSelection();
    void menuTitle();
    void menuTxt();
private:
    float screenSizeX;
    float screenSizeY;

    sf::Texture menuBackground;
    sf::Sprite menuBckSprite;
    sf::RectangleShape selectionBck;
    sf::Vector2u oldScreenSize;
    sf::Font fontTitle;
    sf::Text title;
    sf::Text credit;
    sf::Text names;

};
