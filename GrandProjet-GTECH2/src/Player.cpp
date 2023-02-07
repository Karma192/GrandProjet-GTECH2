#include "Player.hpp"

Player::Player()
{
    playerSprite.setPosition(0, 0);
    playerSprite.setOrigin(32, 32);
    ControllerInput();
    animation.AnimationInit("ressources/sprites/player/idle.png", playerSprite, 1, 64, 64);
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
    setCamera();
}

void Player::Render()
{
    playerUI();
    gameData.window->draw(animation.SpriteAnimation(4, 4, 1, 4, 4));
    //gameData.window->draw(enduranceBarBack);
    gameData.window->draw(enduranceBar);
    gameData.window->draw(lifeBar);
    gameData.window->draw(playerUltiUI);
    gameData.window->draw(playerFirstSpell);
    gameData.window->draw(playerSecondSpell);
    gameData.window->draw(playerThirdSpell);
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
    sf::Vector2f enduranceBarV = gameData.window->mapPixelToCoords(sf::Vector2i(2, 830));
    enduranceBar.setPosition(enduranceBarV);

    /*enduranceBarBack.setSize(sf::Vector2f(300.f, 25.f));
    enduranceBarBack.setFillColor(sf::Color::Black);
    enduranceBarBack.setPosition(2, 2);*/

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
    else if (moveSpeed.y > deadZone)
    {
        sf::Joystick::update();
        MovePlayer();
    }
}

void Player::KeyboardMove()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        playerSprite.move(sf::Vector2f(0.f, -10));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        playerSprite.move(sf::Vector2f(0.f, 10));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        playerSprite.move(sf::Vector2f(-10, 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        playerSprite.move(sf::Vector2f(10, 0.f));
    }
}

void Player::MovePlayer() 
{
    playerSprite.move(moveSpeed.x / playerSpeed, moveSpeed.y / playerSpeed);
}

void Player::setCamera() {
    gameData = GetGameData();
    view = gameData.window->getDefaultView();
    view.setCenter(cube.getPosition());
    gameData.window->setView(view);
}
