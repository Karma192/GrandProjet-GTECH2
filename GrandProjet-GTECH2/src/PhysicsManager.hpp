#pragma once

#include <stdio.h>
#include <vector>
#include "PhysicBody.hpp"

class PhysicsManager
{
private:
	static PhysicsManager* _instance;
	static std::vector<PhysicBody*> _bodies;

public:
	PhysicsManager();
	PhysicsManager(PhysicsManager& other) = delete;

	void operator=(const PhysicsManager&) = delete;

	static PhysicsManager* GetInstance();

	void Update();
	static void AddBody(PhysicBody* body);
};