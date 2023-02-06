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

void PhysicsObject::SetPlayerBounds()
{
	Object1HurtBox = cube.getGlobalBounds();
}

void PhysicsObject::SetObjectBounds()
{
	Object2HurtBox = randomPosObject.getGlobalBounds();
}

void PhysicsObject::SetBoundingBox()
{
	std::cout << "1: " << Object1HurtBox.left << std::endl;
	std::cout << "2: " << Object2HurtBox.left << std::endl;

	if (Object1HurtBox.intersects(Object2HurtBox)) {
		std::cout << "test";
	}
}