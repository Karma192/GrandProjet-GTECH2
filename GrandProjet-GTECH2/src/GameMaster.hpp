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