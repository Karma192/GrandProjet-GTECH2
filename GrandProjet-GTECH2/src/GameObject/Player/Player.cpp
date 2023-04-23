#include "Player.hpp"
#include "../../Instance/GameMaster.hpp"


Player::Player()
{
    SetSprite("Default", sf::Vector2f(1.0f, 1.0f));
    SetPosition(sf::Vector2f(400, 400));
    SetID("Player", "Player");

    _spellsManager = new SpellsManager(this);
    playerHP = 100;
}

Player::~Player()
{
    delete _spellsManager;
}

void Player::Init()
{
    animation.LoadAnimation("ressources/sprites/player/player_tilesheet.png", &Sprite(), 50, 37, 3.f);

    frameIndexIdle = { 0, 1, 2, 3 };
    frameIndexRun = { 8, 9, 10, 11 };
    frameIndexAttack1 = { 44, 45, 46, 47 };
    frameIndexAttack2 = { 48, 49, 50, 51, 52 };
    frameIndexAttackZone = { 55, 56, 57, 58 };
    frameIndexDie = { 65, 66, 67, 68 };
}

void Player::Loop()
{
    _isAttacking = false;
    ControllerMove();
    KeyboardMove();
    MouseUsage();
    PlayerAttack();
    PlayerBasicAttack();
    _spellsManager->UpdateSpell();
}

void Player::Render()
{
    GameMaster::Draw(lifeBar);
    GameMaster::Draw(playerUltiUI);
    GameMaster::Draw(playerUltiUI);

    for (int i = 0; i < 3; i++)
    {
        GameMaster::Draw(playerUITab[i]);
    }
    
    bool canAttack = _cooldownBA <= 0;

    if (_isAttacking && canAttack) 
    {
        GameMaster::Draw(_basicAttack);
        _frame++;
        if (_frame >= _activeFrame)
        {
            _frame = 0;
            ResetBasicAttackCooldown();
        }
    }
    else
    {
		_frame = 0;
        _cooldownBA--;
	}

    playerUI();
    GameMaster::Draw(Sprite());
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
    float lifeBarSize = (playerHP * 300) / 100;
    if (lifeBarSize < 0)
		lifeBarSize = 0;

    lifeBar.setSize(sf::Vector2f(lifeBarSize, 25.f));
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
    _moveDirection.x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    _moveDirection.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
	
	if (_moveDirection.x > deadZone || _moveDirection.y > deadZone ||
        _moveDirection.x < -deadZone || _moveDirection.y < -deadZone)
	{
		MovePlayer();
	}
}

void Player::MouseUsage() 
{
    _playerCenter = Sprite().getPosition();
    _mousePos = sf::Mouse::getPosition(*GameMaster::Window());
    _worldPosition = GameMaster::Window()->mapPixelToCoords(_mousePos, GameMaster::Window()->getView());

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
    Sprite().move(_moveDirection.x / playerSpeed * _modifierSpeed, _moveDirection.y / playerSpeed * _modifierSpeed);
}

void Player::KeyboardMove()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        _moveDirection = sf::Vector2f(0.f, -100.f);
        //animation.Animate(frameIndexRun, 0.2f, true, false, 0);
        MovePlayer();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _moveDirection = sf::Vector2f(0.f, 100.f);
        //animation.Animate(frameIndexRun, 0.2f, true, false, 0);
        MovePlayer();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        _moveDirection = sf::Vector2f(-100.f, 0.f);
        animation.Animate(frameIndexRun, 0.2f, true, true, 0);
        MovePlayer();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _moveDirection = sf::Vector2f(100.f, 0.f);
        animation.Animate(frameIndexRun, 0.2f, true, false, 0);
        MovePlayer();
    }
    else {
        animation.Animate(frameIndexIdle, 0.2f, true, false, 0);
    }
}

sf::Vector2f Player::GetPlayerPosition()
{
    return Sprite().getPosition();
}

float Player::GetPlayerAimDegree()
{
    return angleDegrees;
}

void Player::PlayerAttack()
{
    PlayerBasicAttack();
}

void Player::PlayerBasicAttack()
{
    _basicAttack.setSize(sf::Vector2f(50.f, 50.f));
    _basicAttack.setFillColor(sf::Color::Blue);
    _basicAttack.setPosition(Sprite().getPosition());
    _basicAttack.setRotation(Sprite().getRotation());
    _basicAttack.setOrigin(Sprite().getLocalBounds().width / 2.0f, Sprite().getLocalBounds().height / 2.0f);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        _isAttacking = true;

        if (angleDegrees > 45 && angleDegrees < 135) {
            _basicAttack.setPosition(GetPlayerPosition().x, GetPlayerPosition().y - 40.f);
        }
        if (angleDegrees > 135 && angleDegrees < 225) {
            _basicAttack.setPosition(GetPlayerPosition().x + 40.f, GetPlayerPosition().y);
        }
        if (angleDegrees > 225 && angleDegrees < 315) {
            _basicAttack.setPosition(GetPlayerPosition().x, GetPlayerPosition().y + 40.f);
        }
        if (angleDegrees > 325 || angleDegrees < 45) {
            _basicAttack.setPosition(GetPlayerPosition().x - 40.f, GetPlayerPosition().y);
        }
    }
}