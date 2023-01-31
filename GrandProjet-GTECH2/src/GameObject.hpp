#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "GameMaster.hpp"

class GameObject {
public:
	int id;

	GameObject();
	~GameObject();

	GameData gameData;

	// For initialize all game data
	void InitGameData();
	// Function Init() for construct after prepocessing
	virtual void Init();
	// Boucle du game object
	void Update();
	// Processus en back du game object
	virtual void Loop();
	// Rendu du game object
	virtual void Render();

private:

};