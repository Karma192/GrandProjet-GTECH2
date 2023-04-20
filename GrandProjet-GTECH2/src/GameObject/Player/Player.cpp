#include "Player.hpp"
#include "../../Instance/GameMaster.hpp"


Player::Player()
{
    SetSprite("sprites/player/adventurer-idle.png", sf::Vector2f(3.0f, 3.0f));
    SetPosition(sf::Vector2f(200, 200));
    SetID("Player", "Player");


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
    MouseUsage();
    _stopMoving = false;
    PlayerBasicAttack();

    // Passage à la frame suivante de l'animation
    if (clock.getElapsedTime().asSeconds() > 0.2f)
    {
        if (rectSprite.left == 150)
            rectSprite.left = 0;
        else
            rectSprite.left += 50;

        Sprite()->setTextureRect(rectSprite);
        clock.restart();
    }
}

void Player::Render()
{
    GameMaster::GetInstance()->GetGameData().window->draw(lifeBar);
    GameMaster::GetInstance()->GetGameData().window->draw(playerUltiUI);
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
    GameMaster::GetInstance()->GetGameData().window->draw(*Sprite());
    playerUI();
}

void Player::OnCollisionEnter(PhysicBody* other)
{
    if (other->CompareTag("Enemy"))
    {
		std::cout << "Collision of player with an enemy" << std::endl;
        //std::cout << playerHP << std::endl; 
        playerHP--;
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

void Player::MouseUsage() {
    _playerCenter = Sprite()->getPosition();
    _mousePos = sf::Mouse::getPosition(*GameMaster::GetInstance()->GetGameData().window);
    _worldPosition = GameMaster::GetInstance()->GetGameData().window->mapPixelToCoords(_mousePos, GameMaster::GetInstance()->GetGameData().window->getView());

    float dx = _worldPosition.x - _playerCenter.x;
    float dy = _worldPosition.y - _playerCenter.y;

    float angleRadians = std::atan2(dy, dx);
    angleDegrees = angleRadians * 180 / M_PI;
    angleDegrees += 180;

    //std::cout << angleDegrees << std::endl;

    if (angleDegrees > 360)
    {
        angleDegrees -= 360;
    }
}

void Player::MovePlayer()
{
    Sprite()->move(moveSpeed.x / playerSpeed, moveSpeed.y / playerSpeed);

    if (_dashing)
    {
        playerSpeed = 5;
    }
    if (!_dashing)
    {
        playerSpeed = 20;
    }
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
    return Sprite()->getPosition().x;
}

int Player::GetPlayerYPos()
{
    return Sprite()->getPosition().y;
}

int Player::getPlayerSpeed()
{
    return playerSpeed;
}

void Player::setPlayerSpeed(float OtherSpeed)
{
    playerSpeed = OtherSpeed;
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
    hitboxTest.setPosition(Sprite()->getPosition());
    hitboxTest.setRotation(Sprite()->getRotation());
    hitboxTest.setOrigin(CubeBounds.width / 2.0f, CubeBounds.height / 2.0f);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (angleDegrees > 45 && angleDegrees < 135) {
            hitboxTest.setPosition(GetPlayerXPos(), GetPlayerYPos() - 30.f);
        }
        if (angleDegrees > 135 && angleDegrees < 225) {
            hitboxTest.setPosition(GetPlayerXPos() + 30.f, GetPlayerYPos());
        }
        if (angleDegrees > 225 && angleDegrees < 315) {
            hitboxTest.setPosition(GetPlayerXPos(), GetPlayerYPos() + 30.f);
        }
        if (angleDegrees > 325 || angleDegrees < 45) {
            hitboxTest.setPosition(GetPlayerXPos() - 30.f, GetPlayerYPos());
        }
    }
}