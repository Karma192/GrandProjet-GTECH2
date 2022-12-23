#include "Collision.h"

Collision::Collision() {
	player = new Player();
}

Collision::~Collision() {

}

void Collision::GetBounds() {
	this->player->playerBox = this->player->playerSprite.getGlobalBounds();
	this->enemiesBox = this->enemies->enemiesSprite.getGlobalBounds();
	testCollision();
}

void Collision::testCollision() {
	if (this->player->playerBox.intersects(this->enemiesBox))
	{
		std::cout << "test";
	}
}