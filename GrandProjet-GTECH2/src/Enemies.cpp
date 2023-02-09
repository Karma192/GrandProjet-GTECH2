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
    MoveBase(follow);
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
    //interval for aggro
    sf::Vector2f TargetPos = contextPlayer->cube.getPosition();
    sf::Vector2f FollowPos = cube2.getPosition();
    sf::Vector2f RelatPos = TargetPos - FollowPos;
    float deltaLength = std::sqrt(RelatPos.x * RelatPos.x + RelatPos.y * RelatPos.y);
    if (deltaLength > followRadius) {
        cube2.setPosition(FollowPos + .005f * RelatPos);
    }
    clock.restart();

    distance = std::sqrt((TargetPos.x - FollowPos.x) * (TargetPos.x - FollowPos.x) +
        (TargetPos.y - FollowPos.y) * (TargetPos.y - FollowPos.y));


    if (distance >= 600) 
    {
        cube2.setFillColor(sf::Color::Green);
        follow = false;
        MoveBase(false);
    }
    else if (distance < 600) 
    {
        cube2.setFillColor(sf::Color::Blue);
        cube2.setPosition(FollowPos + .02f * RelatPos);
    }
}

void Enemies::MoveBase(bool)
{
    if (follow)
    {
        FollowTarget(follow);
    }
    else if (!follow)
    {
        srand((unsigned)time(NULL));
        sf::Vector2f FollowPos = cube2.getPosition();
        //unsigned int randomPosX = ((double)rand() / FollowPos.y + 5) * );
        unsigned int randomPosY = rand() % int(FollowPos.y-5) + int(FollowPos.y+5);
        std::cout << randomPosY;
        //cube2.setPosition(randomPosX, randomPosY);
        follow = true;
    }
}