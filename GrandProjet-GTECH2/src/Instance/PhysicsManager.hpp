#pragma once

#include <stdio.h>
#include <vector>
#include "../GameObject/PhysicBody.hpp"

class PhysicsManager
{
private:
	static PhysicsManager* _instance;
	std::vector<PhysicBody*> _bodies;

public:
	PhysicsManager();
	PhysicsManager(PhysicsManager& other) = delete;

	void operator=(const PhysicsManager&) = delete;

	// Fonction pour récupérer l'instance du PhysicsManager
	static PhysicsManager* GetInstance();

	// Fonction pour mettre à jour les collisions
	void Update();
	// Fonction pour ajouter un PhysicBody à la liste des PhysicBody
	void AddBody(PhysicBody* obj);
	//Fonction pour retirer un PhysicBody de la liste des PhysicBody
	void RemoveBody(PhysicBody* body);
};