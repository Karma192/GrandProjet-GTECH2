#pragma once
#include <iostream>

struct player {
	int gold, key;
	float hp, resources, speed, baseSpeed, baseDmg, attackSpeed, speedProjectile, luck;
};

enum {
	MENU = 0,
	LOBBY = 1,
	INGAME = 2,
};

extern int indexScene;

// Function to call for change active scene
void SetActiveScene(int);