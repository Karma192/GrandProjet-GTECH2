#pragma once
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "GameObject.hpp"

class PhysicsObject : public GameObject
{
public:
	PhysicsObject();
	virtual ~PhysicsObject();

	virtual void Loop()override;
	virtual void Render()override;

	void SetPtr(sf::RectangleShape*, sf::RectangleShape*);

private:
	sf::RectangleShape* cubePtr;
	sf::RectangleShape* cube2Ptr;
	sf::FloatRect PlayerHurtbox;
	sf::FloatRect ObjectCollideRect;
	sf::FloatRect EnemiesRect;
	void SetDynamicObject();
	void SetStaticObject();
	Object object;
};

