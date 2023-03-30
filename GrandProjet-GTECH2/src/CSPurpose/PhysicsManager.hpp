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

	// Fonction pour récupérer l'instance du PhysicsManager
	static PhysicsManager* GetInstance();

	// Fonction pour mettre à jour les collisions
	void Update();
	// Fonction pour ajouter un PhysicBody à la liste des PhysicBody
	static void AddBody(PhysicBody* body);
	//Fonction pour retirer un PhysicBody de la liste des PhysicBody
	static void RemoveBody(PhysicBody* body);
};