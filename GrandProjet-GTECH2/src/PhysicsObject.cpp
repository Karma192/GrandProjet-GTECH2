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
	PlayerHurtbox = cubePtr->getGlobalBounds();
}

void PhysicsObject::SetObjectBounds()
{
	ObjectCollideRect = randomPosObject.getGlobalBounds();
	ObjectObtain();
	ObjectCollideRect = randomPosObject2.getGlobalBounds();
	ObjectObtain();
}

void PhysicsObject::SetPlayerDamaged() {

}

void PhysicsObject::SetPlayerCollide() {

}

void PhysicsObject::ObjectObtain()
{
	if (PlayerHurtbox.intersects(ObjectCollideRect)) {
		std::cout << "test";
	}
}

void PhysicsObject::ObjectCollide() {

}