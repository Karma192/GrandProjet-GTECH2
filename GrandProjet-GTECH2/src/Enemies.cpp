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
    GetStunned();
    if (contextPlayer) FollowTarget(follow);
}

void Enemies::Render() 
{
    gameData = GetGameData();
    gameData.window->draw(cube2);
}

void Enemies::Cube2Test()
{
    cube2.setSize(sf::Vector2f(30.f, 30.f));
    //cube2.setFillColor(sf::Color::Blue);
    cube2.setPosition(sf::Vector2f(800, 400));
}

void Enemies::FollowTarget(bool)
{
    sf::Clock clock;
    float interval = 0.001f;
    sf::Vector2f TargetPos = contextPlayer->cube.getPosition();
    sf::Vector2f FollowPos = cube2.getPosition();
    sf::Vector2f RelatPos = TargetPos - FollowPos;
    distance = std::sqrt((TargetPos.x - FollowPos.x) * (TargetPos.x - FollowPos.x) +
        (TargetPos.y - FollowPos.y) * (TargetPos.y - FollowPos.y));


    if (distance <= 600 && follow)
    {
        cube2.setFillColor(sf::Color::Blue);
        follow = true;
        cube2.move(.02f * RelatPos);
        //MoveBase(false);
    }
    else {
        cube2.setFillColor(sf::Color::Green);
    }
}

void Enemies::GetStunned()
{
    sf::FloatRect rect = contextPlayer->hitboxTest.getGlobalBounds();
    sf::FloatRect rect2 = cube2.getGlobalBounds();
    if (contextPlayer->IsAttacking) {
        if (IsDamaged(rect, rect2)) {
            follow = false;
            clock2.restart();
        }
    }
    if (clock2.getElapsedTime().asSeconds() > 2.f) {
        follow = true;
    }
}