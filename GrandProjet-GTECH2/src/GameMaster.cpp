#include "GameMaster.hpp"

GameMaster* GameMaster::instance = nullptr;
GameData GameMaster::data;

GameMaster::GameMaster()
{
	if (instance == nullptr && instance != this) 
	{
		instance = this;
	}
}

GameMaster* GameMaster::GetInstance() 
{
	if (instance == nullptr) 
	{
		instance = new GameMaster();
	}
	return instance;
}

GameData GameMaster::GetGameData()
{
	return data;
}

void GameMaster::SetActiveScene(int value)
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

void GameMaster::SetWindow(RenderWindow* win, Event* e) {
	data.window = win;
	data.event = e;
}
