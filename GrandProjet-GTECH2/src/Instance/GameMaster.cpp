#include "GameMaster.hpp"
#include "../GameObject/GameObject.hpp"
#include "PhysicsManager.hpp"

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

std::vector<GameObject*> GameMaster::GetListGameObject()
{
	return _listGameObject;
}

void GameMaster::AddGameObject(GameObject* obj)
{
	_listGameObject.push_back(obj);
}

void GameMaster::InitObject()
{
#if _DEBUG
	//std::cout << "GameObject Count : \t" << _listGameObject.size() << std::endl;
	//std::cout << "GameMaster::InitGame() started..." << std::endl;
#endif // _DEBUG

	for (int i = 0; i < _listGameObject.size(); i++)
	{
		if (_listGameObject[i] != nullptr)
		{
			if (!_listGameObject[i]->IsInit()) 
			{
				_listGameObject[i]->Init();
			}
		}
	}
#if _DEBUG
	//std::cout << "GameMaster::InitGame() ended..." << std::endl;
#endif // _DEBUG
}

GameData GameMaster::GetGameData()
{
	return data;
}

sf::RenderWindow* GameMaster::Window()
{
	return data.window;
}

sf::Event* GameMaster::Event()
{
	return data.event;
}

void GameMaster::Draw(sf::Drawable& drawable)
{
	data.window->draw(drawable);
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

void GameMaster::SetWindow(sf::RenderWindow* win, sf::Event* e) 
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
			if (_listGameObject[i]->IsDestructed())
			{
				PhysicsManager::GetInstance()->RemoveBody(_listGameObject[i]);
				delete _listGameObject[i];
				_listGameObject.erase(_listGameObject.begin() + i);
			}
		}
	}
}
