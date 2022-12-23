#include "Collision.h"

Collision::Collision() {

}

void Collision::SetPlayer(Player* p) {
	player = p;
}

void Collision::SetEnemies(Enemies* e) {
	enemies = e;
}

Collision::~Collision() {

}

void Collision::GetBounds() {
	//SetPlayer(player);
	this->player->playerBox = this->player->playerSprite.getGlobalBounds();
//	this->enemiesBox = this->enemies->enemiesSprite.getGlobalBounds();
//	testCollision();
}

void Collision::testCollision() {
	if (this->player->playerBox.intersects(this->enemiesBox))
	{
		std::cout << "test";
	}
}