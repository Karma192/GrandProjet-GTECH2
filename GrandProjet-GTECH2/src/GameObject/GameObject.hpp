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

	void Create();

	// Setup des donn�es identitaires du GameObject
	void SetID(std::string name, std::string tag);
	// Initialisation du game object (appelée une seule fois après le constructeur)
	virtual void Init();
	// Boucle du game object
	void Update();
	// Processus en back du game object
	virtual void Loop();
	// Rendu du game object
	virtual void Render();
	// Destruction du game object
	void Destroy();
	// Fonction pour recuperer les bounds du game object
	sf::FloatRect* GetBounds() { return &_sprite->getGlobalBounds(); }
	// Fonction pour r�cuperer le nom du game object
	std::string GetName() { return _name; }
	// Fonction pour définir le sprite
	void SetSprite(std::string file, sf::Vector2f scale);
	// Fonction pour set la position
	void SetPosition(sf::Vector2f position);
	// Fonction pour r�cuperer le sprite du game object
	sf::Sprite* Sprite() { return _sprite; }
	// Fonction pour vérifier si le game object est initialisé
	bool IsInit() { return _init; }
	// Fonction pour vérifier si le game object doit être détruit
	bool IsDestructed() { return _destructed; }

private:
	static int _number;
	std::string _path = "ressources/";

	int _id;
	sf::Sprite* _sprite;
	std::string _name;

	bool _init = false;
	bool _destructed = false;
};