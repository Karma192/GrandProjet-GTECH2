#include "Collision.h"

Collision::Collision() {
	player = new Player();
	enemies = new Enemies();
}

Collision::~Collision() {

}

void Collision::GetBounds() {
	this->playerBox = this->player->playerSprite.getGlobalBounds();
	this->enemiesBox = this->enemies->enemiesSprite.getGlobalBounds();
	std::cout << "globalbounds:" << this->player->playerSprite.getGlobalBounds().width << std::endl;
	std::cout << "Box:" << this->playerBox.width << std::endl;
	this->testCollision();
}

void Collision::testCollision() {
	if (this->playerBox.intersects(this->enemiesBox))
	{
		std::cout << "test";
	}
	if (!this->playerBox.intersects(this->enemiesBox))
	{
		std::cout << "not working" << std::endl;
	}
}