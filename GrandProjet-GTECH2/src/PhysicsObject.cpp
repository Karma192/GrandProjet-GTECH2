#include "PhysicsObject.hpp"

PhysicsObject::PhysicsObject(Player* p)
{
	player = p;
}

PhysicsObject::~PhysicsObject()
{
}

void PhysicsObject::Loop()
{
	SetDynamicObject();
	SetStaticObject();
	Collide(cubePtr, &object.randomPosObject);
	Collide(cube2Ptr, &object.randomPosObject);
	if (player->IsAttacking) {
		IsDamaged(HitboxRect, EnemiesRect);
	}
}

void PhysicsObject::Render()
{
}

void PhysicsObject::SetPtr(sf::RectangleShape* rect, sf::RectangleShape* rect2, sf::RectangleShape* rect3)
{
	cubePtr = rect;
	cube2Ptr = rect2;
	HitBoxPtr = rect3;
}

void PhysicsObject::SetDynamicObject()
{

	HitboxRect = HitBoxPtr->getGlobalBounds();
	PlayerHurtbox = cubePtr->getGlobalBounds();
	EnemiesRect = cube2Ptr->getGlobalBounds();
}

void PhysicsObject::SetStaticObject()
{
	ObjectCollideRect = object.randomPosObject.getGlobalBounds();
	ObjectCollideRect = object.randomPosObject2.getGlobalBounds();
}