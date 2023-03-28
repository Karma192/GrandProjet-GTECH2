#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

struct player {
	int gold, key;
	float hp, resources, speed, baseSpeed, baseDmg, attackSpeed, speedProjectile, luck;
};

struct GameData {
	int indexScene = 0;
	RenderWindow* window = nullptr;
	Event* event = nullptr;
	int indexMap = 0;
};

enum Scene {
	MENU = 0,
	LOBBY = 1,
	INGAME = 2,
};

enum Tag {
	PLAYER,
	ENEMY,
	PROJECTILE,
	ITEM,
};

class GameMaster 
{
protected:
	static GameMaster* instance;
	static GameData data;
public:
	GameMaster();
	GameMaster(GameMaster& other) = delete;

	void operator=(const GameMaster&) = delete;

	static GameMaster* GetInstance();

	// Function for get game's global data
	static GameData GetGameData();
	// Function to call for change active scene
	void SetActiveScene(int);
	// Function for set the window and event
	void SetWindow(RenderWindow*, Event*);
};