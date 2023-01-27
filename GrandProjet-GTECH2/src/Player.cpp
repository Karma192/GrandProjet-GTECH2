﻿#include "Player.hpp"

Player::Player()
{
    playerSprite.setPosition(0, 0);
}

Player::~Player()
{

}

void Player::PlayerLoop()
{
    playerEndurance();
    playerRegenEndurance();
    ControllerMove();

    
}

void Player::PlayerTest(sf::RenderWindow* win)
{
    playerUI();
    //win->draw(enduranceBarBack);
    win->draw(enduranceBar);
    win->draw(lifeBar);
    win->draw(playerUltiUI);
    win->draw(playerFirstSpell);
    win->draw(playerSecondSpell);
    win->draw(playerThirdSpell);
    win->draw(cube);
}

void Player::playerEndurance()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && cd_Endurance >= 2 && endurancePlayer > 0)
    {
        endurancePlayer -= 0.1;
        std::cout << "Il te reste " << endurancePlayer << "de point d'endurance" << std::endl;
        enduranceBar.setScale(endurancePlayer / 100, 1);
    }
    if (endurancePlayer <= 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        std::cout << "Tu peux plus courir" << std::endl;
    }


}

void Player::playerRegenEndurance()
{
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && endurancePlayer <= 100)
    {
        endurancePlayer += 0.1;
        enduranceBar.setScale(endurancePlayer / 100, 1);
        std::cout << "REGEN ENDURANCE : " << endurancePlayer << std::endl;
    }

}

void Player::playerUI()
{
    enduranceBar.setSize(sf::Vector2f(300.f, 25.f));
    enduranceBar.setFillColor(sf::Color::Blue);
    enduranceBar.setPosition(2, 830);

    /*enduranceBarBack.setSize(sf::Vector2f(300.f, 25.f));
    enduranceBarBack.setFillColor(sf::Color::Black);
    enduranceBarBack.setPosition(2, 2);*/

    lifeBar.setSize(sf::Vector2f(300.f, 25.f));
    lifeBar.setFillColor(sf::Color::Green);
    lifeBar.setPosition(2, 800);

    playerUltiUI.setRadius(40);
    playerUltiUI.setFillColor(sf::Color::Transparent);
    playerUltiUI.setOutlineThickness(5);
    playerUltiUI.setOutlineColor(sf::Color::Yellow);
    playerUltiUI.setPosition(30, 880);

    playerFirstSpell.setRadius(20);
    playerFirstSpell.setFillColor(sf::Color::Transparent);
    playerFirstSpell.setOutlineThickness(5);
    playerFirstSpell.setOutlineColor(sf::Color::Green);
    playerFirstSpell.setPosition(140, 920);

}

void Player::PlayerRender(sf::RenderWindow* win)
{

    //sf::Texture texture;

    //if (!texture.loadFromFile("ressources/sprites/player/idle.png"))
    //{
    //    std::cout << "y'a pas d'image" << std::endl;
    //}
    //
    ////left, top, w, h
    //sf::IntRect rectSourceSprite(0, 0, 64, 64);
    //sf::Sprite sprite(texture,rectSourceSprite);
    //sprite.scale(10.0f, 10.0f);
    //
    //float elapsed1 = clock.getElapsedTime().asSeconds();

    //if (elapsed1 >= 1)
    //{
    //    if (rectSourceSprite.left == 256)
    //    {
    //        rectSourceSprite.left = 0;
    //    }
    //    else
    //    {
    //        rectSourceSprite.left += 64;
    //    }s

    //    sprite.setTextureRect(rectSourceSprite);
    //    clock.restart();
    //}

    //win->draw(sprite);

    // w = 900 h = 1200           900x1200
    // un drag 300 400
    // sprite.setTexture(texture);
}


//Je test des trucs sur le Player, cel� sera supprim� (Etienne)
//void Player::PlayerTest(sf::RenderWindow* win)
//{
//    playerTexture.loadFromFile("C:/Users/etien/Pictures/amongus.png");
//    if (!playerTexture.loadFromFile("C:/Users/etien/Pictures/amongus.png"))
//    {
//        std::cout << "y'a pas d'image" << std::endl;
//    }
//    playerSprite.setTexture(playerTexture);
//    win->draw(playerSprite);
//    std::cout << "player:" << playerSprite.getGlobalBounds().width << std::endl;
//} 