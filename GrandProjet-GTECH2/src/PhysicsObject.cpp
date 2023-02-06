#include "PhysicsObject.hpp"

PhysicsObject::PhysicsObject()
{
}

PhysicsObject::~PhysicsObject()
{
}

void PhysicsObject::Loop()
{
	SetPlayerBounds();
	SetObjectBounds();
	SetBoundingBox();
}

void PhysicsObject::Render()
{
}

void PhysicsObject::SetPtr(sf::RectangleShape* rect)
{
	cubePtr = rect;
}

void PhysicsObject::SetPlayerBounds()
{
	Object1HurtBox = cubePtr->getGlobalBounds();
}

void PhysicsObject::SetObjectBounds()
{
	Object2HurtBox = randomPosObject.getGlobalBounds();
}

void PhysicsObject::SetBoundingBox()
{
	if (Object1HurtBox.intersects(Object2HurtBox)) {
		std::cout << "test";
	}
}