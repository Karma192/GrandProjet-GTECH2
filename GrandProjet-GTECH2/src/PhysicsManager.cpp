#include "PhysicsManager.hpp"

PhysicsManager* PhysicsManager::_instance = nullptr;

PhysicsManager::PhysicsManager()
{
	if (_instance == nullptr && _instance != this)
	{
		_instance = this;
	}
}

PhysicsManager* PhysicsManager::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new PhysicsManager();
	}
	return _instance;
}

void PhysicsManager::Update()
{
	for (int i = 0; i < _bodies.size(); i++)
	{
		for (int j = i + 1; j < _bodies.size(); j++)
		{
			if (_bodies[i]->Hitbox()->intersects(*_bodies[j]->Hitbox()))
			{
				_bodies[i]->OnCollisionEnter(_bodies[j]);
				_bodies[j]->OnCollisionEnter(_bodies[i]);
			}
		}
	}
}

void PhysicsManager::AddBody(PhysicBody* body)
{
	_bodies.push_back(body);
}
