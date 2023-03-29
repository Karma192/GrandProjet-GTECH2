#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "GameMaster.hpp"
#include "CSPurpose/PhysicBody.hpp"

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
	// Fonction pour r�cuperer le nom du game object
	std::string GetName() { return _name; }

private:
	std::string _name;
};