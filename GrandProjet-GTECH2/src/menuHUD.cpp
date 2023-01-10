#include "menuHUD.h"

menuHUD::menuHUD()
{

}

menuHUD::~menuHUD()
{
}

void menuHUD::menuRender(sf::RenderWindow* win) {
    menuBackground.loadFromFile("ressources/background.jpg");
    menuBckSprite.setTexture(menuBackground);
    win->draw(menuBckSprite);
}

void menuHUD::menuSelection(sf::RenderWindow* win)
{
    oldScreenSize = win->getSize();
    selectionBck.setFillColor(sf::Color(153, 89, 7, 200));
    selectionBck.setSize(sf::Vector2f(600, 600));
    selectionBck.setOrigin(sf::Vector2f((selectionBck.getSize())/2.0f));
    screenSizeX = float(oldScreenSize.x);
    screenSizeY = float(oldScreenSize.y);
    selectionBck.setPosition(screenSizeX/2.0f, screenSizeY/2.0f);
    win->draw(selectionBck);
}

void menuHUD::menuTitle(sf::RenderWindow* win)
{
    if (!this->heartless.loadFromFile("ressources/fonts/Heartless.ttf"))
    {
        std::cout << "Error TTF Title Font" << std::endl;
    }

    title.setFont(heartless);
    title.setString("Crusade of the Abyss");
    title.setCharacterSize(200);
    sf::FloatRect bounds = title.getLocalBounds();
    float x = bounds.left + bounds.width / 2;
    float y = bounds.top + bounds.height / 2;
    title.setOrigin(x, y);
    title.setFillColor(sf::Color(255, 255, 255, 255));
    title.setPosition(screenSizeX / 2.0f, 100);
    win->draw(title);
}

void menuHUD::menuTxt(sf::RenderWindow* win)
{   
    playRect.setSize(sf::Vector2f(100.f, 100.f));
    playRect.setFillColor(sf::Color::Red);
    win->draw(playRect);
    
    sf::Vector2i mousePos = sf::Mouse::getPosition();
    sf::Vector2f pointfloat(mousePos);
    sf::FloatRect test = playRect.getGlobalBounds();
    if(test.contains(pointfloat)){
        std::cout << "test";
    }
}

