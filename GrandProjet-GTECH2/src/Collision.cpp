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
	this->testCollision();
}

void Collision::testCollision() {
	if (this->playerBox.intersects(this->enemiesBox))
	{
		std::cout << "working";
	}
	if (!this->playerBox.intersects(this->enemiesBox))
	{
		std::cout << "not working" << std::endl;
	}
}