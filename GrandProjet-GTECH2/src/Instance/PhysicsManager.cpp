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
	std::cout << "x : " << _bodies[0]->Hitbox()->left << "\ty : " << _bodies[0]->Hitbox()->top << std::endl;
#endif // _DEBUG

	for (int i = 0; i < _bodies.size(); i++)
	{
		for (int j = i + 1; j < _bodies.size() - 1; j++)
		{
			bool isColliding = _bodies[i]->Hitbox()->intersects(*_bodies[j]->Hitbox());
			bool isNull = _bodies[i]->Hitbox() != nullptr && _bodies[j]->Hitbox() != nullptr;
			bool isTheSame = _bodies[i] == _bodies[j];

			if (isColliding && !isNull && !isTheSame)
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

void PhysicsManager::AddBody(PhysicBody* obj)
{
	_bodies.push_back(obj);
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