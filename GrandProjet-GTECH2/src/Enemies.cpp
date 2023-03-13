#include "Enemies.hpp"

Enemies::Enemies(Player* p) 
{
    contextPlayer = p;
    Cube2Test();
}

Enemies::~Enemies() 
{
    delete contextPlayer;
}

void Enemies::Loop() 
{
    if (contextPlayer) FollowTarget(follow);
}

void Enemies::Render() 
{
    gameData = GetGameData();
    gameData.window->draw(Enemy);
}

void Enemies::Cube2Test()
{
    texture.loadFromFile(ENEMY_TEXTURE);
    Enemy.setTexture(texture);
    Enemy.setPosition(sf::Vector2f(800, 400));
    //Enemy.setTextureRect(enemy);

    //cube2.setSize(sf::Vector2f(30.f, 30.f));
    //cube2.setFillColor(sf::Color::Blue);
    //cube2.setPosition(sf::Vector2f(800, 400));
}

void Enemies::FollowTarget(bool follow)
{


    //if (distance > 300)
    //{
    //    follow = false;
    //    randDir = std::rand() % 4 + 1;
    //    //cube2.setFillColor(sf::Color::Green);
    //    if (ClockMove.getElapsedTime().asSeconds() > 1) {
    //        if (randDir == 1)
    //        {
    //            Enemy.move(0.f, -10);
    //            ClockMove.restart();
    //        }
    //        if (randDir == 2)
    //        {
    //            Enemy.move(0.f, 10);
    //            ClockMove.restart();
    //        }
    //        if (randDir == 3)
    //        {
    //            Enemy.move(10, 0.f);
    //            ClockMove.restart();
    //        }
    //        if (randDir == 4)
    //        {
    //            Enemy.move(-10, 0.f);
    //            ClockMove.restart();
    //        }
    //    }
    //}

}