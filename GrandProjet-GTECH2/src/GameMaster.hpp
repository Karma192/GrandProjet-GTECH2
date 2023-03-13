#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
//#include "GameObject.hpp"

using namespace sf;

struct player {
	int gold, key;
	float hp, resources, speed, baseSpeed, baseDmg, attackSpeed, speedProjectile, luck;
};

struct GameData {
	int indexScene;
	RenderWindow* window;
	Event* event;
	int indexMap = 0;
};

static GameData data;

enum {
	MENU = 0,
	LOBBY = 1,
	INGAME = 2,
};

// Function for get game's global data
GameData GetGameData();
// Function to call for change active scene
void SetActiveScene(int);
// Function for set the window and event
void SetWindow(RenderWindow*, Event*);

// Function for Destroy a GameObject
//void Destroy(GameObject*);