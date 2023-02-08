#pragma once
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "GameObject.hpp"

class PhysicsObject : public Object, public GameObject
{
public:
	PhysicsObject();
	virtual ~PhysicsObject();

	virtual void Loop()override;
	virtual void Render()override;
	void ObjectObtain();
	void ObjectCollide();
	void SetPtr(sf::RectangleShape*, sf::RectangleShape*);
	bool once = false;

private:
	sf::RectangleShape* cubePtr;
	sf::RectangleShape* cube2Ptr;
	sf::FloatRect PlayerHurtbox;
	sf::FloatRect ObjectCollideRect;
	sf::FloatRect EnemiesRect;
	void SetPlayerBounds();
	void SetObjectBounds();
	void SetPlayerDamaged();
	void SetPlayerCollide();
};

