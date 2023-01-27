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

}

void Player::PlayerRender(sf::RenderWindow* win)
{

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

    //    sprite.setTextureRect(rectSourceSprite);
    //    clock.restart();
    //}

    //win->draw(sprite);

    // w = 900 h = 1200           900x1200
    // un drag 300 400
    // sprite.setTexture(texture);
}


//Je test des trucs sur le Player, cel� sera supprim� (Etienne)
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