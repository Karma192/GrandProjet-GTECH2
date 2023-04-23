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
#ifdef _DEBUG
	//std::cout << "Body count : " << _bodies.size() << std::endl;
	//std::cout << "x : " << _bodies[0]->Hitbox()->left << "\ty : " << _bodies[0]->Hitbox()->top << std::endl;
#endif // _DEBUG

	for (int i = 0; i < _bodies.size(); i++)
	{
		for (int j = i + 1; j < _bodies.size(); j++)
		{
			bool isNull = _bodies[i] == nullptr && _bodies[j] == nullptr;
			if (isNull) continue; // Si les deux sont null, on passe à la boucle suivante

			bool isTheSame = _bodies[i] == _bodies[j];
			if (isTheSame) continue; // Si les deux sont les mêmes, on passe à la boucle suivante

			//bool isItTwoWall = _bodies[i]->CompareTag("Wall") && _bodies[j]->CompareTag("Wall");
			//if (isItTwoWall) continue; // Si les deux sont des murs, on passe à la boucle suivante

			//bool thereIsAWall = _bodies[i]->CompareTag("Wall") || _bodies[j]->CompareTag("Wall");
			//if (thereIsAWall) 
			//{
			//	bool isItPlayerAgainstaWall = _bodies[i]->CompareTag("Player") && _bodies[j]->CompareTag("Wall");
			//	if (!isItPlayerAgainstaWall) continue; // Si le joueur entre en collision avec un mur, on passe à la boucle suivante
			//}
			
			bool isColliding = _bodies[i]->Hitbox().intersects(_bodies[j]->Hitbox());
			if (isColliding)
			{
				_bodies[i]->OnCollisionEnter(_bodies[j]);
				_bodies[j]->OnCollisionEnter(_bodies[i]);
			}
		}
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
