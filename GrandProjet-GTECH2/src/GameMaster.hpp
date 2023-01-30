#pragma once
#include <iostream>

struct player {
	int gold, key;
	float hp, resources, speed, baseSpeed, baseDmg, attackSpeed, speedProjectile, luck;
};

struct GameData {
	int indexScene;
};

static GameData data;

enum {
	MENU = 0,
	LOBBY = 1,
	INGAME = 2,
};

GameData GetGameData();
// Function to call for change active scene
void SetActiveScene(int);