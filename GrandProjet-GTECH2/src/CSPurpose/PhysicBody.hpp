#pragma once
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class PhysicBody
{
private:
	sf::FloatRect* _hitbox = nullptr;
	std::string _tag;
public:
	PhysicBody();

	sf::FloatRect* Hitbox() { return _hitbox; }

	// Fonction à override pour déterminer les actions à faire OnCollision
	virtual void OnCollisionEnter(PhysicBody* other);
	// Fonction pour créer la hitbox
	void SetHitbox(sf::FloatRect*);

	// Fonction pour déterminer le tag de l'objet
	void SetCollideTag(std::string tag);
	// Fonction pour comparer le tag de l'objet avec un autre tag
	bool CompareTag(std::string tag);
	// Fonction pour récupérer le tag de l'objet
	std::string GetTag();
};