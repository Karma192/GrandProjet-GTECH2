#include "Enemies.hpp"

Enemies::Enemies() {
    enemiesSprite.setPosition(100, 0);
    enemiesTexture.loadFromFile("C:/Users/etien/Pictures/imposter.png");
    enemiesSprite.setTexture(enemiesTexture);
}

Enemies::~Enemies() {

}

void Enemies::Loop() {

}

void Enemies::Render() {

}

//Je test des trucs sur le Enemies, celà sera supprimé (Etienne)
//void Enemies::EnemiesTest(sf::RenderWindow* win)
//{
//    win->draw(enemiesSprite);
//}
