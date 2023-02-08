#include "Enemies.hpp"

Enemies::Enemies(Player* p) 
{
    //enemiesSprite.setPosition(100, 0);
    //enemiesTexture.loadFromFile("C:/Users/etien/Pictures/imposter.png");
    //enemiesSprite.setTexture(enemiesTexture);

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
    gameData.window->draw(cube2);
}

void Enemies::Cube2Test()
{
    cube2.setSize(sf::Vector2f(30.f, 30.f));
    cube2.setFillColor(sf::Color::Blue);
    cube2.setPosition(sf::Vector2f(800, 400));
}

void Enemies::FollowTarget(bool)
{
    //Radius for Aggro
    float followRadius = 0.1f;
    //interval for aggro
    sf::Vector2f TargetPos = contextPlayer->cube.getPosition();
    sf::Vector2f FollowPos = cube2.getPosition();
    sf::Vector2f RelatPos = TargetPos - FollowPos;
    float deltaLength = std::sqrt(RelatPos.x * RelatPos.x + RelatPos.y * RelatPos.y);
    if (deltaLength > followRadius) {
        cube2.setPosition(FollowPos + .005f * RelatPos);
    }
}

void Enemies::EnemyMove() 
{
    if (!IsFixed) 
    {
        if (follow) 
        {
            FollowTarget(follow);
        }
        else
        {
            //MoveBase();
        }
    }

}