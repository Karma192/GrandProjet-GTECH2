#pragma once

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class GameObject;

class PhysicBody
{
private:
	sf::FloatRect* _hitbox;
	std::string _tag;
	
	// Fonction pour cr�er la hitbox
	void SetHitbox(sf::FloatRect* rect);

public:
	PhysicBody();
	virtual ~PhysicBody() {}

	// Fonction pour r�cup�rer la hitbox
	sf::FloatRect* Hitbox() { return _hitbox; }

	// Fonction � override pour d�terminer les actions � faire OnCollision
	virtual void OnCollisionEnter(PhysicBody* other);
	// Fonction pour comparer le tag de l'objet avec un autre tag
	bool CompareTag(std::string tag);
	// Fonction pour r�cup�rer le tag de l'objet
	std::string GetTag();
	
protected:
	// Fonction pour d�finir le propri�taire du PhysicBody
	void DefineOwnBody(GameObject* go);
	// Fonction pour d�terminer le tag de l'objet
	void SetCollideTag(std::string tag);
};