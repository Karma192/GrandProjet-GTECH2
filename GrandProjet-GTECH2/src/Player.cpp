#include "Player.hpp"

Player::Player()
{
    DisplayPLayer();
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
    Static();
    //setCamera();
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
    
    // DEBUG
    IsAttacking = true;
    gameData.window->draw(hitboxTest);

    //if (isActtk == true && asAttacked == true) 
    //{ 
    //    IsAttacking = true;
    //    gameData.window->draw(hitboxTest);
    //}
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
    gameData.window->draw(playerSprite);
    playerUI();
}

bool Player::collidesWith(CollisionObject* other) {
    if (Enemies* enemy = dynamic_cast<Enemies*>(other)){
        if (playerSprite.getGlobalBounds().intersects(enemy->cube2.getGlobalBounds())) {
            return true;
        }
    }
    if (Object* object = dynamic_cast<Object*>(other)) {
        if (playerSprite.getGlobalBounds().intersects(object->randomPosObject.getGlobalBounds())) {
            return true;
        }
    }
    return false;
}


void Player::handleCollision(CollisionObject* other)
{
    if (dynamic_cast<Enemies*>(other)) {
        std::cout << "EUREKA";
    }
    if (dynamic_cast<Object*>(other)) {
        std::cout << "test";
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

void Player::DisplayPLayer()
{
    animationRunPlayer.InitAnimation("ressources/sprites/player/animations/run/adventurer_run.png", &playerSprite, 50, 37, 6, 0, 3.0f);
    //animationIdlePlayer.InitAnimation("ressources/sprites/player/animations/idle/adventurer_idle.png", &playerSprite, 50, 37, 4, 0, 3.0f);

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
}

void Player::setCamera() {
    gameData = GetGameData();
    view = gameData.window->getDefaultView();
    view.setCenter(playerSprite.getPosition());
    gameData.window->setView(view);
}

void Player::KeyboardMove()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        playerSprite.move(sf::Vector2f(0.f, -5));
        //Destroy();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveSpeed = sf::Vector2f(0.f, 100.f);
        MovePlayer();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        animationRunPlayer.Animate(0.2f, true);
        moveSpeed = sf::Vector2f(-100.f, 0.f);
        MovePlayer();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        animationRunPlayer.Animate(0.2f, false);
        moveSpeed = sf::Vector2f(100.f, 0.f);
        MovePlayer();
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

void Player::Static()
{
    if (moveSpeed.x == 0 && moveSpeed.y == 0)
    {
        //animationIdlePlayer.Animate(0.2f, false);
    }
}

void Player::PlayerBasicAttack()
{
    hitboxTest.setSize(sf::Vector2f(30.f, 30.f));
    hitboxTest.setFillColor(sf::Color::Blue);
    hitboxTest.setPosition(playerSprite.getPosition());

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
