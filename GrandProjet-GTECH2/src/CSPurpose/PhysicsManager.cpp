#include "PhysicsManager.hpp"

PhysicsManager* PhysicsManager::_instance = nullptr;
std::vector<PhysicBody*> PhysicsManager::_bodies;

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
#ifdef _DEBUG
	//std::cout << "Body count : " << _bodies.size() << std::endl;
	std::cout << "x : " << _bodies[1]->Hitbox()->left << "y : " << _bodies[1]->Hitbox()->top << std::endl;
#endif // _DEBUG

	for (int i = 0; i < _bodies.size(); i++)
	{
		for (int j = i + 1; j < _bodies.size() - 1; j++)
		{
			if (_bodies[i]->Hitbox() != nullptr && _bodies[j]->Hitbox() != nullptr
				&& _bodies[i]->GetTag() != _bodies[j]->GetTag()
				&& _bodies[i] != _bodies[j]
				&& _bodies[i]->Hitbox()->intersects(*_bodies[j]->Hitbox()))
			{
				_bodies[i]->OnCollisionEnter(_bodies[j]);
				_bodies[j]->OnCollisionEnter(_bodies[i]);
			}
		}
#ifdef _DEBUG
		//std::cout << "Tag" << i << " : " << _bodies[i]->GetTag() << std::endl;
#endif // _DEBUG
	}
}

void PhysicsManager::AddBody(PhysicBody* body)
{
	_bodies.push_back(body);
}

void PhysicsManager::RemoveBody(PhysicBody* body)
{
	if (!_bodies.empty())
	{
		for (int i = 0; i < _bodies.size(); i++)
		{
			if (_bodies[i] == body)
			{
				delete _bodies[i];
				_bodies.erase(_bodies.begin() + i);
			}
		}
	}
}
