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
    GetStunned();
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

void Enemies::FollowTarget(bool follow)
{
<<<<<<< Updated upstream
    //Radius for Aggro
    //interval for aggro
    sf::Clock clock;
    float interval = 0.001f;
    sf::Vector2f TargetPos = contextPlayer->cube.getPosition();
    sf::Vector2f FollowPos = cube2.getPosition();
    sf::Vector2f RelatPos = TargetPos - FollowPos;
    float deltaLength = std::sqrt(RelatPos.x * RelatPos.x + RelatPos.y * RelatPos.y);
    if (deltaLength > followRadius) {
        cube2.move(.005f * RelatPos);
    }
    clock.restart();
=======
    FollowPos = cube2.getPosition();
    TargetPos = contextPlayer->cube.getPosition();
    RelatPos = TargetPos - FollowPos;
>>>>>>> Stashed changes

    distance = std::sqrt((TargetPos.x - FollowPos.x) * (TargetPos.x - FollowPos.x) +
        (TargetPos.y - FollowPos.y) * (TargetPos.y - FollowPos.y));

    if (distance > 300)
    {
        follow = false;
        randDir = std::rand() % 4 + 1;
        cube2.setFillColor(sf::Color::Green);
        if (ClockMove.getElapsedTime().asSeconds() > 1) {
            if (randDir == 1)
            {
                cube2.move(0.f, -10);
                ClockMove.restart();
            }
            if (randDir == 2)
            {
                cube2.move(0.f, 10);
                ClockMove.restart();
            }
            if (randDir == 3)
            {
                cube2.move(10, 0.f);
                ClockMove.restart();
            }
            if (randDir == 4)
            {
                cube2.move(-10, 0.f);
                ClockMove.restart();
            }
        }
    }
    if (distance < 300)
    {
        follow = true;
        cube2.setFillColor(sf::Color::Blue);
        cube2.move(0.01f * RelatPos);
    }
}

<<<<<<< Updated upstream
void Enemies::GetStunned()
{
    sf::FloatRect rect = contextPlayer->hitboxTest.getGlobalBounds();
    sf::FloatRect rect2 = cube2.getGlobalBounds();
    if (contextPlayer->IsAttacking) {
        if (IsDamaged(rect, rect2)) {
            followRadius = 1000000.f;
            clock2.restart();
        }
    }
    if (clock2.getElapsedTime().asSeconds() > 1.f) {
        followRadius = 1.f;
    }
}
=======
>>>>>>> Stashed changes
