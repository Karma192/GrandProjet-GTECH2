#include "Collision.h"

Collision::Collision() {

}

Collision::Collision(Player* p) {
	player = p;
}

Collision::Collision(Enemies* e) {
	enemies = e;
}

Collision::~Collision() {

}

void Collision::GetBounds() {
	this->player->playerBox = this->player->playerSprite.getGlobalBounds();
//	this->enemiesBox = this->enemies->enemiesSprite.getGlobalBounds();
	testCollision();
}

void Collision::testCollision() {
	if (this->player->playerBox.intersects(this->enemiesBox))
	{
		std::cout << "test";
	}
}