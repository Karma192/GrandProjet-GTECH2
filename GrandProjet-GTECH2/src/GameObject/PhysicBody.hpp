#pragma once

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class GameObject;

class PhysicBody
{
public:
	PhysicBody();
	virtual ~PhysicBody();

	// Fonction pour récupérer la hitbox
	sf::FloatRect Hitbox();
	// Fonction à override pour déterminer les actions à faire OnCollision
	virtual void OnCollisionEnter(PhysicBody* other);
	// Fonction pour comparer le tag de l'objet avec un autre tag
	bool CompareTag(std::string tag);
	// Fonction pour récupérer le tag de l'objet
	std::string GetTag();
	
private:
	GameObject* _owner;
	std::string _tag;

protected:
	// Fonction pour définir le PhysicBody
	void DefineOwnBody(GameObject* go);
	// Fonction pour déterminer le tag de l'objet
	void SetCollideTag(std::string tag);
};