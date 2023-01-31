#include "Enemies.hpp"

Enemies::Enemies() {
    enemiesSprite.setPosition(100, 0);
}

Enemies::~Enemies() {

}

void Enemies::Loop() {

}

void Enemies::Render() {

}

//Je test des trucs sur le Enemies, cela sera supprimé (Etienne)
//void Enemies::EnemiesTest(sf::RenderWindow* win)
//{
//    enemiesTexture.loadFromFile("C:/Users/etien/Pictures/imposter.png");
//    if (!enemiesTexture.loadFromFile("C:/Users/etien/Pictures/imposter.png"))
//    {
//        std::cout << "y'a pas d'image" << std::endl;
//    }
//    enemiesSprite.setTexture(enemiesTexture);
//    win->draw(enemiesSprite);
//}