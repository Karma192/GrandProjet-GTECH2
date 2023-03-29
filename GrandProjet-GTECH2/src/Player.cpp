#include "Player.hpp"


Player::Player()
{
    CubeTest();
    SetID("Player", "Enemy");
    sf::FloatRect* hitbox = &cube.getGlobalBounds();
    SetHitbox(hitbox);
}

Player::~Player()
{

}

void Player::Loop()
{
    playerEndurance();
    playerRegenEndurance();
    ControllerMove();
    KeyboardMove();
    PlayerAttack();
    setCamera();
    _stopMoving = false;
    //std::cout << "Player direction : " << _playerDirection << std::endl;
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

void Player::OnCollisionEnter(PhysicBody* other)
{
    if (other->CompareTag("Enemy"))
    {
		std::cout << "Collision of player with an enemy" << std::endl;
	}
}

void Player::playerEndurance()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && cd_Endurance >= 2 && endurancePlayer > 0)
    {
        endurancePlayer -= 0.5;
        enduranceBar.setScale(endurancePlayer / 100, 1);
    }
    if (endurancePlayer <= 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
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
