#include "Player.hpp"

Player::Player()
{
    playerSprite.setPosition(0, 0);
    ControllerInput();
}

Player::~Player() 
{

}

void Player::PlayerLoop() 
{
    playerEndurance();
    playerRegenEndurance();
    ControllerMove();
    
}

void Player::PlayerTest(sf::RenderWindow* win)
{
    playerUI();
    //win->draw(enduranceBarBack);
    win->draw(enduranceBar);
    win->draw(lifeBar);
    win->draw(playerUltiUI);
    win->draw(playerFirstSpell);
    win->draw(playerSecondSpell);
    win->draw(playerThirdSpell);
    win->draw(cube);
}


    //sf::Texture texture;

    //if (!texture.loadFromFile("ressources/sprites/player/idle.png"))
    //{
    //    std::cout << "y'a pas d'image" << std::endl;
    //}
    //
    ////left, top, w, h
    //sf::IntRect rectSourceSprite(0, 0, 64, 64);
    //sf::Sprite sprite(texture,rectSourceSprite);
    //sprite.scale(10.0f, 10.0f);
    //
    //float elapsed1 = clock.getElapsedTime().asSeconds();

    //if (elapsed1 >= 1)
    //{
    //    if (rectSourceSprite.left == 256)
    //    {
    //        rectSourceSprite.left = 0;
    //    }
    //    else
    //    {
    //        rectSourceSprite.left += 64;
    //    }s

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
    enduranceBar.setPosition(2, 830);

    /*enduranceBarBack.setSize(sf::Vector2f(300.f, 25.f));
    enduranceBarBack.setFillColor(sf::Color::Black);
    enduranceBarBack.setPosition(2, 2);*/

    lifeBar.setSize(sf::Vector2f(300.f, 25.f));
    lifeBar.setFillColor(sf::Color::Green);
    lifeBar.setPosition(2, 800);

    playerUltiUI.setRadius(40);
    playerUltiUI.setFillColor(sf::Color::Transparent);
    playerUltiUI.setOutlineThickness(5);
    playerUltiUI.setOutlineColor(sf::Color::Yellow);
    playerUltiUI.setPosition(30, 880);

    playerFirstSpell.setRadius(20);
    playerFirstSpell.setFillColor(sf::Color::Transparent);
    playerFirstSpell.setOutlineThickness(5);
    playerFirstSpell.setOutlineColor(sf::Color::Green);
    playerFirstSpell.setPosition(140, 920);

    playerSecondSpell.setRadius(20);
    playerSecondSpell.setFillColor(sf::Color::Transparent);
    playerSecondSpell.setOutlineThickness(5);
    playerSecondSpell.setOutlineColor(sf::Color::Green);
    playerSecondSpell.setPosition(200, 920);

    playerThirdSpell.setRadius(20);
    playerThirdSpell.setFillColor(sf::Color::Transparent);
    playerThirdSpell.setOutlineThickness(5);
    playerThirdSpell.setOutlineColor(sf::Color::Green);
    playerThirdSpell.setPosition(260, 920);
 

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
    else if (moveSpeed.y > deadZone)
    {
        sf::Joystick::update();
        MovePlayer();
    }
}

void Player::MovePlayer() {
    cube.move(1, 1);
}

//Je test des trucs sur le Player, celà sera supprimé (Etienne)
//void Player::PlayerTest(sf::RenderWindow* win)
//{
//    playerTexture.loadFromFile("C:/Users/etien/Pictures/amongus.png");
//    if (!playerTexture.loadFromFile("C:/Users/etien/Pictures/amongus.png"))
//    {
//        std::cout << "y'a pas d'image" << std::endl;
//    }
//    playerSprite.setTexture(playerTexture);
//    win->draw(playerSprite);
//    std::cout << "player:" << playerSprite.getGlobalBounds().width << std::endl;
//}