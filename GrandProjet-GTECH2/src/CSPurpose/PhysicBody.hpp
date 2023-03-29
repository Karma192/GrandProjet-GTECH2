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

	// Fonction � override pour d�terminer les actions � faire OnCollision
	virtual void OnCollisionEnter(PhysicBody* other);
	// Fonction pour cr�er la hitbox
	void SetHitbox(sf::FloatRect*);

	// Fonction pour d�terminer le tag de l'objet
	void SetCollideTag(std::string tag);
	// Fonction pour comparer le tag de l'objet avec un autre tag
	bool CompareTag(std::string tag);
	// Fonction pour r�cup�rer le tag de l'objet
	std::string GetTag();
};