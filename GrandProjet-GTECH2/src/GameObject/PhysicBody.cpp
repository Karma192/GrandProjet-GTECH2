#include "PhysicBody.hpp"
#include "../Instance/PhysicsManager.hpp"
#include "GameObject.hpp"

PhysicBody::PhysicBody()
{
	_hitbox = new sf::FloatRect();
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

void PhysicBody::DefineOwnBody(GameObject* go)
{
	_owner = go;
	SetHitbox(go->GetBounds());
	PhysicsManager::AddBody(this);
}

void PhysicBody::SetHitbox(sf::FloatRect* rect)
{
	_hitbox = rect;
}

void PhysicBody::SetCollideTag(std::string tag)
{
	_tag = tag;
}

bool PhysicBody::CompareTag(std::string tag)
{
	return _tag == tag;
}

std::string PhysicBody::GetTag()
{
	return _tag;
}
