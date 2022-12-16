#include "Player.hpp"

Player::Player() 
{

}

Player::~Player() 
{

}

void Player::PlayerLoop() 
{

}

void Player::PlayerRender() 
{

    sf::Texture texture;

    if (!texture.loadFromFile("ressources/sprites/player/1.png"))
    {
        std::cout << "y'a pas d'image" << std::endl;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
	
}