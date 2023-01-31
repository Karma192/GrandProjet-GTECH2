#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemies.hpp"
#include "Object.hpp"
#include "GameObject.hpp"

class Collision : public GameObject
{
public:
	Collision();
	~Collision();

	void GetBounds();
	void testCollision();

private:

	Player* player;
	Enemies* enemies;
	Object* object;

	sf::FloatRect playerBox;
	sf::FloatRect objectBox;
	sf::FloatRect enemiesBox;
};