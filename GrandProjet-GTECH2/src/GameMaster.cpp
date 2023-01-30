#include "GameMaster.hpp"

void SetActiveScene(int index) {
	switch (index) {
	case MENU:
		indexScene = MENU;
		break;
	case LOBBY:
		indexScene = LOBBY;
		break;
	case INGAME:
		indexScene = INGAME;
		break;
	default:
		indexScene = MENU;
		break;
	}
}