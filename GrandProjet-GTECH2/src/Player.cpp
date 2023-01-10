#include "Player.hpp"

Player::Player()
{
    playerSprite.setPosition(0, 0);
}

Player::~Player() 
{

}

void Player::PlayerLoop() 
{
    playerEndurance();
    playerRegenEndurance();
}

void Player::PlayerRender(sf::RenderWindow* win)
{
    playerEnduranceUI();
    win->draw(enduranceBar);
    win->draw(enduranceBarBack);
  
}

void Player::playerEndurance()
{
    //std::cout << "TEST" << std::endl;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && cd_Endurance >= 2 && endurancePlayer > 0)
    {
        endurancePlayer -= 1;
        std::cout << "Il te reste " << endurancePlayer << "de point d'endurance" << std::endl; 
    }
    if(endurancePlayer == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        std::cout << "Tu peux plus courir" << std::endl;
    }

    float endurancePercent = static_cast<float>(endurancePlayer / 10000);
    enduranceBar.setSize(sf::Vector2f(enduranceBar.getPosition().x * endurancePercent, enduranceBar.getPosition().y));
}

void Player::playerRegenEndurance()
{
    if (endurancePlayer == 0)
    {
        if (cd_Endurance >= 5 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            endurancePlayer += 5;
            std::cout << "REGEN ENDURANCE : " << endurancePlayer << std::endl;
        }
    }
}

void Player::playerEnduranceUI()
{
    enduranceBar.setSize(sf::Vector2f(300.f, 25.f));
    enduranceBar.setFillColor(sf::Color::Green);
    enduranceBar.setPosition(960, 540);

    enduranceBar = enduranceBarBack;
    enduranceBarBack.setFillColor(sf::Color(25, 25, 25, 200)); 
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

