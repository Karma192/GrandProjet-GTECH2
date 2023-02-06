#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>

class PhysicsObject
{
public:
	PhysicsObject();
	virtual ~PhysicsObject();
	void SetBoundingBox(sf::RectangleShape, sf::RectangleShape);

private:
	sf::FloatRect Object1HurtBox;
	sf::FloatRect Object2HurtBox;
};

