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
	void SetBoundingBox();
	void SetPtr(sf::RectangleShape*);

private:
	sf::RectangleShape* cubePtr;
	sf::FloatRect Object1HurtBox;
	sf::FloatRect Object2HurtBox;
	void SetPlayerBounds();
	void SetObjectBounds();
};

