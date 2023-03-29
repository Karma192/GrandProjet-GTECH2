#include "Player.hpp"
#include "ToNextScene.hpp"
#include "GameMaster.hpp"

Player::Player()
{
    DisplayPLayer();
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
        // idle
    if (moveSpeed.x == 0 && moveSpeed.y == 0)
    {
        animationPlayer.Animate(4, 7, 1, 1, 0.2f, false);
    }
}

void Player::Render()
{
    GameMaster::GetInstance()->GetGameData().window->draw(enduranceBar);
    GameMaster::GetInstance()->GetGameData().window->draw(lifeBar);
    GameMaster::GetInstance()->GetGameData().window->draw(playerUltiUI);
    for (int i = 0; i < 3; i++)
    {
        GameMaster::GetInstance()->GetGameData().window->draw(playerUITab[i]);
    }
    
    if (isActtk == true && asAttacked == true) 
    { 
        IsAttacking = true;
        GameMaster::GetInstance()->GetGameData().window->draw(hitboxTest);
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
    GameMaster::GetInstance()->GetGameData().window->draw(playerSprite);
    playerUI();
}

bool Player::collidesWith(CollisionObject* other) {
    if (Enemies* enemy = dynamic_cast<Enemies*>(other)){
        if (playerSprite.getGlobalBounds().intersects(enemy->enemySlime.getGlobalBounds())) {
            return true;
        }
    }
    if (Object* object = dynamic_cast<Object*>(other)) {
        if (playerSprite.getGlobalBounds().intersects(object->randomPosObject.getGlobalBounds())) {
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
    sf::Vector2f lifeBarV = GameMaster::GetInstance()->GetGameData().window->mapPixelToCoords(sf::Vector2i(2, 800));
    lifeBar.setPosition(lifeBarV);

    playerUltiUI.setRadius(40);
    playerUltiUI.setFillColor(sf::Color::Transparent);
    playerUltiUI.setOutlineThickness(5);
    playerUltiUI.setOutlineColor(sf::Color::Yellow);
    sf::Vector2f playerUltiUIV = GameMaster::GetInstance()->GetGameData().window->mapPixelToCoords(sf::Vector2i(30,880));
    playerUltiUI.setPosition(playerUltiUIV);

    // j = position sur l'écran sur l'axe x
    int j = 140;
    for (int i = 0; i < 3; i++)
    {
        playerUITab[i].setRadius(20);
        playerUITab[i].setFillColor(sf::Color::Transparent);
        playerUITab[i].setOutlineThickness(5);
        playerUITab[i].setOutlineColor(sf::Color::Green);
        sf::Vector2f playerUiSpellPosition = GameMaster::GetInstance()->GetGameData().window->mapPixelToCoords(sf::Vector2i(j, 920));
        playerUITab[i].setPosition(playerUiSpellPosition);
        j += 60;
    }

}

void Player::DisplayPLayer()
{
    animationPlayer.InitAnimation("ressources/sprites/player/adventurer_sprite_sheet.png", &playerSprite, 3.f, 50, 37);

    playerSprite.setPosition(sf::Vector2f(200, 200));
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
    playerSprite.move(moveSpeed.x / playerSpeed, moveSpeed.y / playerSpeed);
    rotation = std::atan2(moveSpeed.y, moveSpeed.x) * 180.0f / 3.14159265358979323846;
    playerSprite.setRotation(rotation);
}

void Player::setCamera() {
    view = GameMaster::GetInstance()->GetGameData().window->getDefaultView();
    view.setCenter(playerSprite.getPosition());
    GameMaster::GetInstance()->GetGameData().window->setView(view);
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
            animationPlayer.Animate(6, 7, 2, 2, 0.2f, true);
            moveSpeed = sf::Vector2f(-100.f, 0.f);
            _playerDirection = 3;
            MovePlayer();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            animationPlayer.Animate(6, 7, 2, 2, 0.2f, false);
            moveSpeed = sf::Vector2f(100.f, 0.f);
            _playerDirection = 4;
            MovePlayer();
        }
    }

}

int Player::GetPlayerXPos()
{
    return playerSprite.getPosition().x;
}

int Player::GetPlayerYPos()
{
    return playerSprite.getPosition().y;
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
    hitboxTest.setPosition(playerSprite.getPosition());
    hitboxTest.setRotation(playerSprite.getRotation());
    hitboxTest.setOrigin(CubeBounds.width / 2.0f, CubeBounds.height / 2.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        hitboxTest.setPosition(GetPlayerXPos(), GetPlayerYPos());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        hitboxTest.setPosition(GetPlayerXPos(), GetPlayerYPos());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        hitboxTest.setPosition(GetPlayerXPos(), GetPlayerYPos());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        hitboxTest.setPosition(GetPlayerXPos(), GetPlayerYPos());
    }
}
