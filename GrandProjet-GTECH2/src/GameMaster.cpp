#include "GameMaster.hpp"

GameData GetGameData() 
{
	return data;
}

void SetActiveScene(int value) 
{
	switch (value) {
	case MENU:
		data.indexScene = MENU;
		break;
	case LOBBY:
		data.indexScene = LOBBY;
		break;
	case INGAME:
		data.indexScene = INGAME;
		break;
	default:
		data.indexScene = MENU;
		break;
	}
}

void SetWindow(RenderWindow* win, Event* e) {
	data.window = win;
	data.event = e;
}