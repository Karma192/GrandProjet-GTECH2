#pragma once
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "Player.hpp"
#include "GameObject.hpp"

class PhysicsObject : public GameObject
{
public:
	PhysicsObject() = default;
	PhysicsObject(Player* p);
	virtual ~PhysicsObject();

	virtual void Loop()override;
	virtual void Render()override;

	void SetPtr(sf::RectangleShape*, sf::RectangleShape*, sf::RectangleShape*);

private:
	sf::RectangleShape* cubePtr;
	sf::RectangleShape* cube2Ptr;
	sf::FloatRect PlayerHurtbox;
	sf::FloatRect ObjectCollideRect;
	sf::FloatRect EnemiesRect;
	sf::FloatRect HitboxRect;
	sf::RectangleShape* HitBoxPtr;
	void SetDynamicObject();
	void SetStaticObject();
	Object object;
	Player* player;
};

