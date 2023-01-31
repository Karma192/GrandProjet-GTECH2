#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "GameMaster.hpp"

class GameObject {
public:
	int id;

	GameObject() { InitGameData(); Init(); }
	~GameObject();

	static GameData gameData;

	// Function Init() for construct after prepocessing
	virtual void Init();
	// Boucle du game object
	void Update();
	// Processus en back du game object
	virtual void Loop();
	// Rendu du game object
	virtual void Render();

private:
	// Set game data
	void InitGameData();

};