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
    win->draw(enduranceBarBack);
    win->draw(enduranceBar);

    
}

void Player::playerEndurance()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && cd_Endurance >= 2 && endurancePlayer > 0)
    {
        endurancePlayer -= 0.1;
        std::cout << "Il te reste " << endurancePlayer << "de point d'endurance" << std::endl; 
        enduranceBar.setScale(endurancePlayer / 100, 1); 
    }
    if(endurancePlayer <= 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
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

void Player::playerEnduranceUI()
{
    enduranceBar.setSize(sf::Vector2f(300.f, 25.f));
    enduranceBar.setFillColor(sf::Color::Blue);
    enduranceBar.setPosition(2, 2);
 
    enduranceBarBack.setSize(sf::Vector2f(300.f, 25.f));
    enduranceBarBack.setFillColor(sf::Color::Black);
    enduranceBarBack.setPosition(2, 2);

    
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

