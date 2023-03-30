#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "CollisionObject.h"

class GameObject : public CollisionObject {
public:
	bool _destructed = false;

	GameObject();
	virtual ~GameObject();

	// Boucle du game object
	void Update();
	// Processus en back du game object
	virtual void Loop();
	// Rendu du game object
	virtual void Render();
	//Destruction du game object
	void Destroy();

private:
	void SetData();
};