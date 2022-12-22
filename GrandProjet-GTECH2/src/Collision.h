#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemies.hpp"

class Collision
{
public:
	Player* player;
	Enemies* enemies;

	Collision(Player* p);
	Collision(Enemies* e);

	Collision();
	~Collision();

	void GetBounds();
	void testCollision();

private:

	sf::FloatRect enemiesBox;
};
