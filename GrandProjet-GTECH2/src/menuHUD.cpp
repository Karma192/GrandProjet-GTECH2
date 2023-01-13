#include "menuHUD.h"

menuHUD::menuHUD()
{
    selectionBck.setFillColor(sf::Color(153, 89, 7, 200));
    selectionBck.setSize(sf::Vector2f(600, 600));

    menuBackground.loadFromFile("ressources/background.jpg");
    menuBckSprite.setTexture(menuBackground);

    title.setFont(heartless);
    title.setString("Crusade of the Abyss");
    title.setCharacterSize(200);
    title.setFillColor(sf::Color(255, 255, 255, 255));    

    playRect.setSize(sf::Vector2f(200.f, 50.f));
    playRect.setFillColor(sf::Color::Red);
}

menuHUD::~menuHUD()
{
}

void menuHUD::menuRender(sf::RenderWindow* win) {

    win->draw(menuBckSprite);
}

void menuHUD::menuSelection(sf::RenderWindow* win)
{
    oldScreenSize = win->getSize();
    selectionBck.setOrigin(sf::Vector2f((selectionBck.getSize()) / 2.0f));
    screenSizeX = float(oldScreenSize.x);
    screenSizeY = float(oldScreenSize.y);

    selectionBck.setPosition(screenSizeX / 2.0f, screenSizeY / 2.0f);
    win->draw(selectionBck);
}

void menuHUD::menuTitle(sf::RenderWindow* win)
{
    if (!this->heartless.loadFromFile("ressources/fonts/Heartless.ttf"))
    {
        std::cout << "Error TTF Title Font" << std::endl;
    }

    titleBounds = title.getLocalBounds();
    /*std::cout << titleBounds.left << titleBounds.top << std::endl;*/
    float x = titleBounds.left + titleBounds.width / 2;
    float y = titleBounds.top + titleBounds.height / 2;
    title.setOrigin(x, y);
    title.setPosition(screenSizeX / 2.0f, 100);
    win->draw(title);
}

void menuHUD::menuTxt(sf::RenderWindow* win)
{
    playBounds = playRect.getGlobalBounds();
    float x = playBounds.width / 2;
    float y = playBounds.height / 2;
    playRect.setOrigin(x, y);
    playRect.setPosition(screenSizeX / 2.0f, selectionBck.getPosition().y / 3);

    sf::Vector2i mousePos = sf::Mouse::getPosition(*win);
    sf::Vector2f pointfloat(mousePos);

    std::cout << "playRect: " << playRect.getPosition().x << " " << playRect.getPosition().y << std::endl;
    std::cout << "mousePos: " << pointfloat.x << " " << pointfloat.y << std::endl;

    if(playBounds.contains(pointfloat)){
        std::cout << "collision detected" << std::endl;
    }

    win->draw(playRect);
}