#include "PhysicsObject.hpp"

PhysicsObject::PhysicsObject()
{
}

PhysicsObject::~PhysicsObject()
{
}

void PhysicsObject::SetBoundingBox(sf::RectangleShape Object1, sf::RectangleShape Object2)
{
	Object1HurtBox = Object1.getGlobalBounds();
	Object2HurtBox = Object2.getGlobalBounds();
	if (Object1HurtBox.intersects(Object2HurtBox)) {
		std::cout << "test";
	}
}