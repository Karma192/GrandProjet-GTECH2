#include "Player.hpp"
#include "ToNextScene.hpp"


Player::Player()
{
    CubeTest();
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
}

void Player::Render()
{
    gameData = GetGameData();
    gameData.window->draw(enduranceBar);
    gameData.window->draw(lifeBar);
    gameData.window->draw(playerUltiUI);
    gameData.window->draw(playerFirstSpell);
    gameData.window->draw(playerSecondSpell);
    gameData.window->draw(playerThirdSpell);
    
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
                cube.setOrigin(0, 0);
                _wallTouched++;
                if (cube.getGlobalBounds().left < (map->wallet->GetRoom(0)->rect[i].getGlobalBounds().left + map->wallet->GetRoom(0)->rect[i].getGlobalBounds().width)) {
                    _collideLeft = true;
                    std::cout << "left" << std::endl;
                }
                if ((cube.getGlobalBounds().left + cube.getGlobalBounds().width) > map->wallet->GetRoom(0)->rect[i].getGlobalBounds().left) {
                    _collideRight = true;
                    std::cout << "right" << std::endl;
                }
                if (cube.getGlobalBounds().top < (map->wallet->GetRoom(0)->rect[i].getGlobalBounds().top + map->wallet->GetRoom(0)->rect[i].getGlobalBounds().height)) {
                    _collideUp = true;
                    std::cout << "up" << std::endl;
                }
                if ((cube.getGlobalBounds().top + cube.getGlobalBounds().height) > map->wallet->GetRoom(0)->rect[i].getGlobalBounds().top) {
                    _collideDown = true;
                    std::cout << "down" << std::endl;
                }
                    return true;
            }
            _collideUp = false;
            _collideDown = false;
            _collideLeft = false;
            _collideRight = false;
        }
    }
	return false;
}


void Player::handleCollision(CollisionObject* other)
{
	if (dynamic_cast<Enemies*>(other)) {
        
	}
	if (dynamic_cast<Object*>(other)) {

    }
	if (dynamic_cast<MapGenerator*>(other)) {
        
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

    //For FireBall
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

void  Player::CubeTest()
{
	cube.setSize(sf::Vector2f(30.f, 30.f));
	cube.setFillColor(sf::Color::Red);
	cube.setPosition(sf::Vector2f(200, 200));
    CubeBounds = cube.getLocalBounds();
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
    gameData = GetGameData();
    view = gameData.window->getDefaultView();
    view.setCenter(cube.getPosition());
    gameData.window->setView(view);
}

void Player::KeyboardMove()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !_collideUp)
    {
        moveSpeed = sf::Vector2f(0.f, -100.f);
        MovePlayer();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !_collideDown)
    {
        moveSpeed = sf::Vector2f(0.f, 100.f);
        MovePlayer();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !_collideLeft)
    {
        moveSpeed = sf::Vector2f(-100.f, 0.f);
        MovePlayer();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !_collideRight)
    {
        moveSpeed = sf::Vector2f(100.f, 0.f);
        MovePlayer();
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
