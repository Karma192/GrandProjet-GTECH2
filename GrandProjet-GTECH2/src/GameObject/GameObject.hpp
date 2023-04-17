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


	// Setup des donn�es identitaires du GameObject
	void SetID(std::string name, std::string tag);
	// Initialisation du game object
	virtual void Init();
	// Boucle du game object
	void Update();
	// Processus en back du game object
	virtual void Loop();
	// Rendu du game object
	virtual void Render();
	// Destruction du game object
	void Destroy();
	// Fonction pour r�cuperer les bounds du game object
	sf::FloatRect* GetBounds() { return &_sprite.getGlobalBounds(); }
	// Fonction pour r�cuperer le nom du game object
	std::string GetName() { return _name; }
	// Fonction pour r�cuperer le sprite du game object
	sf::Sprite* GetSprite() { return &_sprite; }

	bool IsInit() { return _init; }
	bool IsDestructed() { return _destructed; }

protected:
	sf::Sprite _sprite;
	sf::FloatRect _hurtbox;
	std::string _name;
	
	bool _init = false;
	bool _destructed = false;
};