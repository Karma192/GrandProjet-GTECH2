#include "PhysicsObject.hpp"

PhysicsObject::PhysicsObject()
{
}

PhysicsObject::~PhysicsObject()
{
}

void PhysicsObject::Loop()
{
	SetDynamicObject();
	SetStaticObject();
	Collide(PlayerHurtbox, EnemiesRect);
}

void PhysicsObject::Render()
{
}

void PhysicsObject::SetPtr(sf::RectangleShape* rect, sf::RectangleShape* rect2)
{
	cubePtr = rect;
	cube2Ptr = rect2;
}

void PhysicsObject::SetDynamicObject()
{
	PlayerHurtbox = cubePtr->getGlobalBounds();
	EnemiesRect = cube2Ptr->getGlobalBounds();
}

void PhysicsObject::SetStaticObject()
{
	ObjectCollideRect = object.randomPosObject.getGlobalBounds();
	ObjectCollideRect = object.randomPosObject2.getGlobalBounds();
}