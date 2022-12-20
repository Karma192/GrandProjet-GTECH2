#include "Projectiles.h"

Projectiles::Projectiles() {

}

Projectiles::Projectiles(Player* p) {
	player = p;
}

Projectiles::Projectiles(Enemies* e) {
	enemies = e;
}

Projectiles::~Projectiles() {

}

void Projectiles::GetBounds() {
	this-> playerBox = this->player->playerSprite.getGlobalBounds();
	this-> enemiesBox = this->enemies->enemiesSprite.getGlobalBounds();
	testCollision();
}

void Projectiles::testCollision() {
	if (this->playerBox.intersects(this->enemiesBox))
	{
		std::cout << "test";
	}
}