﻿#include "Player.hpp"
#include "ToNextScene.hpp"


Player::Player()
{
    CubeTest();
    this->playerHP = 20;
}

Player::~Player()
{

}

void Player::Loop()
{
    ControllerMove();
    KeyboardMove();
    PlayerAttack();
    setCamera();
    _stopMoving = false;
    PlayerBasicAttack();

}

void Player::Render()
{
    gameData = GameMaster::GetInstance()->GetGameData();
    gameData.window->draw(enduranceBar);
    gameData.window->draw(lifeBar);
    gameData.window->draw(playerUltiUI);
    for (int i = 0; i < 3; i++)
    {
        gameData.window->draw(playerUITab[i]);
    }
    
    if (isActtk == true && asAttacked == true) 
    { 
        IsAttacking = true;
        gameData.window->draw(hitboxTest);
    }
    if (cdBasicAttack.getElapsedTime().asSeconds() >= 0.1f)
    {
        isActtk = false;
        asAttacked = false;
        cdBasicAttack.restart();
    }
    else
    {
        IsAttacking = false;
        isActtk = true;
    }
    gameData.window->draw(cube);
    playerUI();
}

bool Player::collidesWith(CollisionObject* other) {
    if (Enemies* enemy = dynamic_cast<Enemies*>(other)){
        if (cube.getGlobalBounds().intersects(enemy->cube2.getGlobalBounds())) {
            return true;
        }
    }
    if (Object* object = dynamic_cast<Object*>(other)) {
        if (cube.getGlobalBounds().intersects(object->randomPosObject.getGlobalBounds())) {
            return true;
        }
    }
    if (ToNextScene* object = dynamic_cast<ToNextScene*>(other)) {
        if (cube.getGlobalBounds().intersects(object->_sprite.getGlobalBounds())) {
            return true;
        }
    }
    return false;
}


void Player::handleCollision(CollisionObject* other)
{
	if (dynamic_cast<Enemies*>(other)) 
    {
        //std::cout << playerHP << std::endl; 
        playerHP--;
	}
	if (dynamic_cast<Object*>(other)) 
    {

    }
	if (dynamic_cast<MapGenerator*>(other)) 
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && _playerDirection != 1)
        {
            moveSpeed = sf::Vector2f(0.f, -100.f);
            MovePlayer();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && _playerDirection != 2)
        {
            moveSpeed = sf::Vector2f(0.f, 100.f);
            MovePlayer();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && _playerDirection != 3)
        {
            moveSpeed = sf::Vector2f(-100.f, 0.f);
            MovePlayer();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && _playerDirection != 4)
        {
            moveSpeed = sf::Vector2f(100.f, 0.f);
            MovePlayer();
        }
        _stopMoving = true;
    }
}


void Player::playerUI()
{
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

    // j = position sur l'écran sur l'axe x
    int j = 140;
    for (int i = 0; i < 3; i++)
    {
        playerUITab[i].setRadius(20);
        playerUITab[i].setFillColor(sf::Color::Transparent);
        playerUITab[i].setOutlineThickness(5);
        playerUITab[i].setOutlineColor(sf::Color::Green);
        sf::Vector2f playerUiSpellPosition = gameData.window->mapPixelToCoords(sf::Vector2i(j, 920));
        playerUITab[i].setPosition(playerUiSpellPosition);
        j += 60;
    }

}

void  Player::CubeTest()
{
	cube.setSize(sf::Vector2f(30.f, 30.f));
	cube.setFillColor(sf::Color::Red);
	cube.setPosition(sf::Vector2f(200, 200));
    CubeBounds = cube.getGlobalBounds();
    cube.setOrigin(CubeBounds.width/2.0f,CubeBounds.height/2.0f);
}

void Player::ControllerMove()
{
	float deadZone = 5.f;
	moveSpeed.x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	moveSpeed.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
	

	if (moveSpeed.x > deadZone || moveSpeed.y > deadZone || 
		moveSpeed.x < -deadZone || moveSpeed.y < -deadZone)
	{
		MovePlayer();
	}

}

void Player::MovePlayer()
{
    cube.move(moveSpeed.x / playerSpeed, moveSpeed.y / playerSpeed);
    rotation = std::atan2(moveSpeed.y, moveSpeed.x) * 180.0f / 3.14159265358979323846;
    cube.setRotation(rotation);
}

void Player::setCamera() {
    gameData = GameMaster::GetInstance()->GetGameData();
    view = gameData.window->getDefaultView();
    view.setCenter(cube.getPosition());
    gameData.window->setView(view);
}

void Player::KeyboardMove()
{
    if (!_stopMoving) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            moveSpeed = sf::Vector2f(0.f, -100.f);
            _playerDirection = 1;
            MovePlayer();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            moveSpeed = sf::Vector2f(0.f, 100.f);
            _playerDirection = 2;
            MovePlayer();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            moveSpeed = sf::Vector2f(-100.f, 0.f);
            _playerDirection = 3;
            MovePlayer();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            moveSpeed = sf::Vector2f(100.f, 0.f);
            _playerDirection = 4;
            MovePlayer();
        }
    }

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
    PlayerBasicAttack();
    asAttacked = true;
}

void Player::PlayerBasicAttack()
{  
    hitboxTest.setSize(sf::Vector2f(30.f, 30.f));
    hitboxTest.setFillColor(sf::Color::Blue);
    hitboxTest.setPosition(cube.getPosition());
    hitboxTest.setRotation(cube.getRotation());
    hitboxTest.setOrigin(CubeBounds.width / 2.0f, CubeBounds.height / 2.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        hitboxTest.setPosition(GetPlayerXPos(), GetPlayerYPos() - 30.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        hitboxTest.setPosition(GetPlayerXPos(), GetPlayerYPos() + 30.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        hitboxTest.setPosition(GetPlayerXPos() - 30.f, GetPlayerYPos());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        hitboxTest.setPosition(GetPlayerXPos() + 30.f, GetPlayerYPos());
    }
}
