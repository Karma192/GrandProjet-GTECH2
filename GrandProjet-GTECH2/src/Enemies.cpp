#include "Enemies.hpp"

Enemies::Enemies() {
    //enemiesSprite.setPosition(100, 0);
    //enemiesTexture.loadFromFile("C:/Users/etien/Pictures/imposter.png");
    //enemiesSprite.setTexture(enemiesTexture);

    Cube2Test();
}

Enemies::~Enemies() {

}

void Enemies::Loop() {
    FollowTarget();
}

void Enemies::Render() {
    gameData = GetGameData();
    gameData.window->draw(cube2);
}

void Enemies::Cube2Test()
{
    cube2.setSize(sf::Vector2f(30.f, 30.f));
    cube2.setFillColor(sf::Color::Blue);
    cube2.setPosition(sf::Vector2f(400, 400));
}

void Enemies::FollowTarget()
{

    Player play;
    //Radius for Aggro
    float followRadius = 10.f;
    //interval for aggro

    sf::Clock clock;
    float interval = 0.1f;

    if (clock.getElapsedTime().asSeconds() > interval)
    {
        sf::Vector2f TargetPos = play.cube.getPosition();
        sf::Vector2f FollowPos = cube2.getPosition();
        sf::Vector2f RelatPos = TargetPos - FollowPos;
        float deltaLength = std::sqrt(RelatPos.x * RelatPos.x + RelatPos.y * RelatPos.x);
        if (deltaLength > followRadius) {
            cube2.setPosition(FollowPos + 0.5f * RelatPos);
        }
        clock.restart();
    }
}

//Je test des trucs sur le Enemies, celà sera supprimé (Etienne)
//void Enemies::EnemiesTest(sf::RenderWindow* win)
//{
//    win->draw(enemiesSprite);
//}
