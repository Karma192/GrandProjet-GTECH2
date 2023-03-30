#include "Player.hpp"
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

        cube.setTextureRect(rectSprite);
        clock.restart();
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
    GameMaster::GetInstance()->GetGameData().window->draw(cube);
    playerUI();
}

bool Player::collidesWith(CollisionObject* other) {
    if (Enemies* enemy = dynamic_cast<Enemies*>(other)) {
        if (cube.getGlobalBounds().intersects(enemy->cube2.getGlobalBounds())) {
            return true;
        }
    }
    if (Object* object = dynamic_cast<Object*>(other)) {
        if (cube.getGlobalBounds().intersects(object->randomPosObject.getGlobalBounds())) {
            return true;
        }
    }
    if (MapGenerator* map = dynamic_cast<MapGenerator*>(other)) {
        for (int i = 0; i < map->wallet->GetRoom(0)->rect.size(); i++) {
            if (cube.getGlobalBounds().intersects(map->wallet->GetRoom(0)->rect[i].getGlobalBounds())) {
                return true;
            }
        }
        return false;
    }
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

void Player::CubeTest()
{
    // Load the sprite texture
    playerTexture.loadFromFile("ressources/sprites/player/adventurer-idle.png");

    cube.setTexture(playerTexture);
    cube.scale(3.0f, 3.0f);
    cube.setPosition(sf::Vector2f(200, 200));

    sf::IntRect rectDefaultSprite = sf::IntRect(50, 0, 50, 37);
    rectSprite = rectDefaultSprite;

    sf::Vector2f center(cube.getLocalBounds().width / 2.f, cube.getLocalBounds().height / 2.f);
    cube.setOrigin(center);

    cube.setTextureRect(rectSprite);
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
    _playerCenter = cube.getPosition();
    _mousePos = sf::Mouse::getPosition(*GameMaster::GetInstance()->GetGameData().window);
    _worldPosition = GameMaster::GetInstance()->GetGameData().window->mapPixelToCoords(_mousePos, GameMaster::GetInstance()->GetGameData().window->getView());

    float dx = _worldPosition.x - _playerCenter.x;
    float dy = _worldPosition.y - _playerCenter.y;

    float angleRadians = std::atan2(dy, dx);
    angleDegrees = angleRadians * 180 / M_PI;
    angleDegrees += 180;

    std::cout << angleDegrees << std::endl;

    if (angleDegrees > 360)
    {
        angleDegrees -= 360;
    }
}

void Player::MovePlayer()
{
    cube.move(moveSpeed.x / playerSpeed, moveSpeed.y / playerSpeed);
    rotation = std::atan2(moveSpeed.y, moveSpeed.x) * 180.0f / M_PI;
    cube.setRotation(rotation);
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