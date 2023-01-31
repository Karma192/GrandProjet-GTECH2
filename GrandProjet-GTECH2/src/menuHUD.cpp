#include "menuHUD.h"

menuHUD::menuHUD()
{

}

menuHUD::~menuHUD()
{

}

void menuHUD::Loop() 
{

}

void menuHUD::Render() 
{
    menuBackground.loadFromFile("ressources/background.jpg");
    menuBckSprite.setTexture(menuBackground);
    gameData.window->draw(menuBckSprite);
    menuSelection();
    menuTitle();
}

void menuHUD::menuSelection()
{
    oldScreenSize = gameData.window->getSize();
    selectionBck.setFillColor(sf::Color(153, 89, 7, 200));
    selectionBck.setSize(sf::Vector2f(600, 600));
    selectionBck.setOrigin(sf::Vector2f((selectionBck.getSize()) / 2.0f));
    screenSizeX = float(oldScreenSize.x);
    screenSizeY = float(oldScreenSize.y);
    selectionBck.setPosition(screenSizeX / 2.0f, screenSizeY / 2.0f);
    gameData.window->draw(selectionBck);
}

void menuHUD::menuTitle()
{
    if (!this->fontTitle.loadFromFile("ressources/fonts/Heartless.ttf"))
    {
        std::cout << "Error TTF Title Font" << std::endl;
    }

    title.setFont(fontTitle);
    title.setString("Crusade of the Abyss");
    title.setCharacterSize(200);
    sf::FloatRect bounds = title.getLocalBounds();
    float x = bounds.left + bounds.width / 2;
    float y = bounds.top + bounds.height / 2;
    title.setOrigin(x, y);
    title.setFillColor(sf::Color(255, 255, 255, 255));
    title.setPosition(screenSizeX / 2.0f, 100);
    gameData.window->draw(title);
}

void menuHUD::menuTxt()
{

}
