#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "GameMaster.hpp"
#include "PhysicsObject.hpp"

class GameObject : PhysicsObject {
public:
	int id;

	GameObject();
	virtual ~GameObject();

	GameData gameData;

	// Boucle du game object
	void Update();
	// Processus en back du game object
	virtual void Loop();
	// Rendu du game object
	virtual void Render();

private:

};