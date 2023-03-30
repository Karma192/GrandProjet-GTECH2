#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "PhysicBody.hpp"

class GameObject : public PhysicBody
{
public:
	GameObject();
	virtual ~GameObject();

	bool _destructed = false;

	// Setup des donn�es identitaires du GameObject
	void SetID(std::string name, std::string tag);
	// Boucle du game object
	void Update();
	// Processus en back du game object
	virtual void Loop();
	// Rendu du game object
	virtual void Render();
	// Destruction du game object
	void Destroy();
	// Fonction pour r�cuperer le sprite du game object
	sf::FloatRect* GetBounds() { return &_sprite.getGlobalBounds(); }
	// Fonction pour r�cuperer le nom du game object
	std::string GetName() { return _name; }

private:
	sf::Sprite _sprite;
	std::string _name;
};