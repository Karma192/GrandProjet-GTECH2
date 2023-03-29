#include "GameMaster.hpp"

GameMaster* GameMaster::instance = nullptr;
GameData GameMaster::data;
std::vector<GameObject*> GameMaster::_listGameObject;

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

std::vector<GameObject*> GameMaster::GetListGameObject()
{
	return _listGameObject;
}

void GameMaster::AddGameObject(GameObject* obj)
{
	_listGameObject.push_back(obj);
}

GameData GameMaster::GetGameData()
{
	return data;
}

void GameMaster::SetActiveScene(int value)
{
	switch (value) 
	{
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

void GameMaster::SetWindow(RenderWindow* win, Event* e) 
{
	data.window = win;
	data.event = e;
}

void GameMaster::Purge()
{
	if (!_listGameObject.empty())
	{
		for (int i = 0; i < _listGameObject.size()-1; i++) 
		{
			if (_listGameObject[i]->_destructed)
			{
				delete _listGameObject[i];
				_listGameObject.erase(_listGameObject.begin() + i);
				
			}
		}
	}
}
