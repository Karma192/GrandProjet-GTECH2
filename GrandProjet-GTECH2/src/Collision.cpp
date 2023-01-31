#include "Collision.hpp"

Collision::Collision() {
	player = new Player();
	enemies = new Enemies();
	object = new Object();
}

Collision::~Collision() {

}

void Collision::GetBounds() {
	this->playerBox = this->player->cube.getGlobalBounds();
	this->objectBox = this->object->randomPosObject.getGlobalBounds();
	this->enemiesBox = this->enemies->enemiesSprite.getGlobalBounds();
	std::cout << "globalbounds:" << this->player->cube.getGlobalBounds().left << std::endl;
	std::cout << "Box:" << this->playerBox.width << std::endl;
	this->testCollision();
}

void Collision::testCollision() {
	if (this->playerBox.intersects(this->objectBox))
	{
		std::cout << "test";
	}
	if (!this->playerBox.intersects(this->enemiesBox))
	{

	}
}