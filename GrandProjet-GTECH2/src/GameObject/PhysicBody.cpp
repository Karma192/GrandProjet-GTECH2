#include "PhysicBody.hpp"
#include "../Instance/PhysicsManager.hpp"
#include "GameObject.hpp"

PhysicBody::PhysicBody()
{
	_tag = "Default";
}

PhysicBody::~PhysicBody()
{
	//delete _owner;
}

sf::FloatRect PhysicBody::Hitbox()
{
	return _owner->GetBounds();
}

void PhysicBody::OnCollisionEnter(PhysicBody* other)
{
	// Ici c'est un exemple de comment on peut utiliser les tags pour faire des collisions

	if (other->CompareTag("Player"))
	{
		std::cout << "Collision with player" << std::endl;
	}

	if (other->CompareTag("Enemy"))
	{
		std::cout << "Collision with enemy" << std::endl;
	}
}

bool PhysicBody::CompareTag(std::string tag)
{
	return _tag == tag;
}

std::string PhysicBody::GetTag()
{
	return _tag;
}

void PhysicBody::DefineOwnBody(GameObject* go)
{
	_owner = go;
	PhysicsManager::GetInstance()->AddBody(this);
}

void PhysicBody::SetCollideTag(std::string tag)
{
	_tag = tag;
}
