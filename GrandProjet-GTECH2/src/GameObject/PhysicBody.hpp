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

	// Fonction pour r�cup�rer la hitbox
	sf::FloatRect Hitbox();
	// Fonction � override pour d�terminer les actions � faire OnCollision
	virtual void OnCollisionEnter(PhysicBody* other);
	// Fonction pour comparer le tag de l'objet avec un autre tag
	bool CompareTag(std::string tag);
	// Fonction pour r�cup�rer le tag de l'objet
	std::string GetTag();
	
private:
	GameObject* _owner;
	std::string _tag;

protected:
	// Fonction pour d�finir le PhysicBody
	void DefineOwnBody(GameObject* go);
	// Fonction pour d�terminer le tag de l'objet
	void SetCollideTag(std::string tag);
};