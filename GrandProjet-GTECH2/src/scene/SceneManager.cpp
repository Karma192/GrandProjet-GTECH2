#include "SceneManager.hpp"
#include "../Camera.hpp"

SceneManager::SceneManager() 
{
}

SceneManager::~SceneManager()
{
}

// Switch between scene's Loop
void SceneManager::Update()
{
	SwitchScene();
}

// Function for switch between all scenes
void SceneManager::SwitchScene()
{
	switch (GameMaster::GetInstance()->GetGameData().indexScene)
	{
	case MENU:
		menu.Update();
#ifdef _DEBUG
		std::cout << "C'est le menu !" << std::endl;
#endif // DEBUG
		break;

	case LOBBY:
		lobby.Update();
#ifdef _DEBUG
		//std::cout << "C'est le lobby !" << std::endl;
#endif // DEBUG
		break;

	case INGAME:
		ingame.Update();
#ifdef _DEBUG
		std::cout << "C'est le ingame !" << std::endl;
#endif // DEBUG
		break;

	default:
		break;
	}
}