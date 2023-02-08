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
	SetPlayerDamaged();
}

void PhysicsObject::Render()
{
}

void PhysicsObject::SetPtr(sf::RectangleShape* rect, sf::RectangleShape* rect2)
{
	cubePtr = rect;
	cube2Ptr = rect2;
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
	EnemiesRect = cube2Ptr->getGlobalBounds();
	SetPlayerCollide();
}

void PhysicsObject::SetPlayerCollide() {
	if (PlayerHurtbox.intersects(EnemiesRect)) {
		std::cout << "ouais";
	}
}

void PhysicsObject::ObjectObtain()
{
	if (PlayerHurtbox.intersects(ObjectCollideRect)) {
		
	}
}

void PhysicsObject::ObjectCollide() {

}