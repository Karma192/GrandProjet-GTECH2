#pragma once
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class GameObject;

class PhysicBody
{
private:
	GameObject* _owner;
	sf::FloatRect* _hitbox;
	std::string _tag;
	
	// Fonction pour créer la hitbox
	void SetHitbox(sf::FloatRect* rect);
public:
	PhysicBody(GameObject* gameObject);
	virtual ~PhysicBody() {}

	// Fonction pour récupérer la hitbox
	sf::FloatRect* Hitbox() { return _hitbox; }

	// Fonction à override pour déterminer les actions à faire OnCollision
	virtual void OnCollisionEnter(PhysicBody* other);
	// Fonction pour définir le propriétaire du PhysicBody
	void DefineOwnBody(GameObject* go);
	// Fonction pour déterminer le tag de l'objet
	void SetCollideTag(std::string tag);
	// Fonction pour comparer le tag de l'objet avec un autre tag
	bool CompareTag(std::string tag);
	// Fonction pour récupérer le tag de l'objet
	std::string GetTag();
};