#include "Collision.h"

Collision::Collision() {
	player = new Player();
	enemies = new Enemies();
}

Collision::~Collision() {

}

void Collision::GetBounds() {
	std::cout << "Player:";
	std::cout << this->player->playerSprite.getPosition().x << this->player->playerSprite.getPosition().y << std::endl;
	std::cout << "Enemies:";
	std::cout << this->enemies->enemiesSprite.getPosition().x << this->enemies->enemiesSprite.getPosition().y << std::endl;
	this->playerBox = this->player->playerSprite.getGlobalBounds();
	this->enemiesBox = this->enemies->enemiesSprite.getGlobalBounds();
	testCollision();
}

void Collision::testCollision() {
	if (this->playerBox.intersects(this->enemiesBox))
	{
		std::cout << "test";
	}
}