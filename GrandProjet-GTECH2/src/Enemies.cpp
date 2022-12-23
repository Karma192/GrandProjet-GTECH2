#include "Enemies.hpp"

Enemies::Enemies() {

}

Enemies::~Enemies() {

}

void Enemies::EnemiesLoop() {

}

void Enemies::EnemiesRender() {

}

//Je test des trucs sur le Player, celà sera supprimé (Etienne)
void Enemies::EnemiesTest(sf::RenderWindow* win)
{
    enemiesTexture.loadFromFile("C:/Users/etien/Pictures/imposter.png");
    if (!enemiesTexture.loadFromFile("C:/Users/etien/Pictures/imposter.png"))
    {
        std::cout << "y'a pas d'image" << std::endl;
    }
    enemiesSprite.setTexture(enemiesTexture);
    enemiesSprite.setPosition(100, 0);
    win->draw(enemiesSprite);
}