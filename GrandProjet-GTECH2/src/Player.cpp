﻿#include "Player.hpp"

Player::Player()
{
    ControllerInput();
    
}

Player::~Player()
{

}

void Player::Loop()
{
    playerEndurance();
    playerRegenEndurance();
    ControllerMove();
<<<<<<< Updated upstream
<<<<<<< Updated upstream
    setCamera();
=======
    KeyboardMove();

>>>>>>> Stashed changes
=======
    KeyboardMove();
    setCamera();
    PlayerAttack();
>>>>>>> Stashed changes
}

void Player::Render()
{
    playerUI();
    gameData = GetGameData();
    gameData.window->draw(enduranceBar);
    gameData.window->draw(lifeBar);
    gameData.window->draw(playerUltiUI);
    gameData.window->draw(playerFirstSpell);
    gameData.window->draw(playerSecondSpell);
    gameData.window->draw(playerThirdSpell);
    gameData.window->draw(cube);
    if (isActtk) gameData.window->draw(hitboxTest);
    
}

void Player::playerEndurance()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        endurancePlayer -= 0.1;
        enduranceBar.setScale(endurancePlayer / 100, 1);
    }
    if (endurancePlayer <= 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        //Ici le joueur ne peut plus courir 
    }
}

void Player::playerRegenEndurance()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && endurancePlayer <= 100)
    {
        endurancePlayer += 0.1;
        enduranceBar.setScale(endurancePlayer / 100, 1);
    }

}

void Player::playerUI()
{
    enduranceBar.setSize(sf::Vector2f(300.f, 25.f));
    enduranceBar.setFillColor(sf::Color::Blue);
    sf::Vector2f enduranceBarV = gameData.window->mapPixelToCoords(sf::Vector2i(2, 830));
    enduranceBar.setPosition(enduranceBarV);

    lifeBar.setSize(sf::Vector2f(300.f, 25.f));
    lifeBar.setFillColor(sf::Color::Green);
    sf::Vector2f lifeBarV = gameData.window->mapPixelToCoords(sf::Vector2i(2, 800));
    lifeBar.setPosition(lifeBarV);

    playerUltiUI.setRadius(40);
    playerUltiUI.setFillColor(sf::Color::Transparent);
    playerUltiUI.setOutlineThickness(5);
    playerUltiUI.setOutlineColor(sf::Color::Yellow);
    sf::Vector2f playerUltiUIV = gameData.window->mapPixelToCoords(sf::Vector2i(30,880));
    playerUltiUI.setPosition(playerUltiUIV);

    playerFirstSpell.setRadius(20);
    playerFirstSpell.setFillColor(sf::Color::Transparent);
    playerFirstSpell.setOutlineThickness(5);
    playerFirstSpell.setOutlineColor(sf::Color::Green);
    sf::Vector2f PlayerFirstSpellV = gameData.window->mapPixelToCoords(sf::Vector2i(140, 920));
    playerFirstSpell.setPosition(PlayerFirstSpellV);

    playerSecondSpell.setRadius(20);
    playerSecondSpell.setFillColor(sf::Color::Transparent);
    playerSecondSpell.setOutlineThickness(5);
    playerSecondSpell.setOutlineColor(sf::Color::Green);
    sf::Vector2f playerSecondSpellV = gameData.window->mapPixelToCoords(sf::Vector2i(200, 920));
    playerSecondSpell.setPosition(playerSecondSpellV);

    playerThirdSpell.setRadius(20);
    playerThirdSpell.setFillColor(sf::Color::Transparent);
    playerThirdSpell.setOutlineThickness(5);
    playerThirdSpell.setOutlineColor(sf::Color::Green);
    sf::Vector2f playerThirdSpellV = gameData.window->mapPixelToCoords(sf::Vector2i(260, 920));
    playerThirdSpell.setPosition(playerThirdSpellV);
}

void  Player::ControllerInput()
{
    cube.setSize(sf::Vector2f(30.f, 30.f));
    cube.setFillColor(sf::Color::Red);
    cube.setPosition(sf::Vector2f(200, 200));
}

void Player::ControllerMove()
{
    float deadZone = 20.f;
    moveSpeed.x = (sf::Joystick::getAxisPosition(0, sf::Joystick::X));
    moveSpeed.y = (sf::Joystick::getAxisPosition(0, sf::Joystick::Y));

    if (moveSpeed.x < -deadZone)
    {
        sf::Joystick::update();
        MovePlayer();
    }
    else if (moveSpeed.x > deadZone)
    {
        sf::Joystick::update();
        MovePlayer();
    }
    else if (moveSpeed.y < -deadZone)
    {
        sf::Joystick::update();
        MovePlayer();
    }
    else if (moveSpeed.x > deadZone)
    {
        sf::Joystick::update();
        MovePlayer();
    }
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
void Player::KeyboardMove()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        cube.move(sf::Vector2f(0.f, -5));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        cube.move(sf::Vector2f(0.f, 5));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        cube.move(sf::Vector2f(-5, 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        cube.move(sf::Vector2f(5, 0.f));
    }
}

>>>>>>> Stashed changes
void Player::MovePlayer() 
{
=======
void Player::KeyboardMove()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        cube.move(sf::Vector2f(0.f, -1));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        cube.move(sf::Vector2f(0.f, 1));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        cube.move(sf::Vector2f(-1, 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        cube.move(sf::Vector2f(1, 0.f));
    }
}

void Player::MovePlayer() {
>>>>>>> Stashed changes
    cube.move(moveSpeed.x / playerSpeed, moveSpeed.y / playerSpeed);
}

<<<<<<< Updated upstream
void Player::setCamera() {
=======
void Player::setCamera() 
{
    gameData = GetGameData();
>>>>>>> Stashed changes
    /*view = gameData.window->getDefaultView();
    view.setCenter(cube.getPosition());
    gameData.window->setView(view);*/
}

int Player::GetPlayerXPos()
{
    return cube.getPosition().x;
}

int Player::GetPlayerYPos()
{
    return cube.getPosition().y;
}



void Player::PlayerAttack()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        PlayerBasicAttack();
    }

}

void Player::PlayerBasicAttack()
{
    isActtk = true;
    hitboxTest.setSize(sf::Vector2f(30.f, 40.f));
    hitboxTest.setFillColor(sf::Color::Blue);
    hitboxTest.setPosition(GetPlayerXPos() + 30.f, GetPlayerYPos() - 5);
    if (test.getElapsedTime().asSeconds() >= 2.f)
    {
        isActtk = false;
    }
 
    
}