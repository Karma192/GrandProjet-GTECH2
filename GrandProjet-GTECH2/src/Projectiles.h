#pragma once
#include <SFML/Graphics.hpp>
#include "scene/SceneManager.hpp"
#include "Player.hpp"
#include "Enemies.hpp"

class Projectiles
{
public:
	Player* player;
	Enemies* enemies;

	Projectiles(Player* p);
	Projectiles(Enemies* e);

	Projectiles();
	~Projectiles();

	void GetBounds();
	void testCollision();

private:
	sf::FloatRect playerBox;
	sf::FloatRect enemiesBox;
};
