#include "PhysicBody.hpp"
#include "PhysicsManager.hpp"

PhysicBody::PhysicBody()
{
	PhysicsManager::GetInstance()->AddBody(this);
}

void PhysicBody::OnCollisionEnter(PhysicBody* other)
{
	//Here is an example of how to use the CompareTag function
	//and the OnCollisionEnter function

	if (other->CompareTag("Player"))
	{
		std::cout << "Collision with player" << std::endl;
	}

	if (other->CompareTag("Enemy"))
	{
		std::cout << "Collision with enemy" << std::endl;
	}
}

void PhysicBody::SetHitbox(sf::Vector2f coord, sf::Vector2f size)
{
	_hitbox.left = coord.x;
	_hitbox.top = coord.y;
	_hitbox.width = size.x;
	_hitbox.height = size.y;
}

void PhysicBody::SetCollideTag(std::string tag)
{
	_tag = tag;
}

bool PhysicBody::CompareTag(std::string tag)
{
	if (_tag == tag)
		return true;
	else
		return false;
}
