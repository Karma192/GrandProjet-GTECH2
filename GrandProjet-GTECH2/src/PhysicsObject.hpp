#pragma once
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
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
	void SetPtr(sf::RectangleShape*);

private:
	sf::RectangleShape* cubePtr;
	sf::FloatRect PlayerHurtbox;
	sf::FloatRect ObjectCollideRect;
	void SetPlayerBounds();
	void SetObjectBounds();
	void SetPlayerDamaged();
	void SetPlayerCollide();
};

