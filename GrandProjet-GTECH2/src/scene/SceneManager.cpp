#include "SceneManager.hpp"
#include "../Instance/Camera.hpp"

SceneManager::SceneManager() 
{
	actualScene = new Menu();
	indexScene = 0;
}

SceneManager::~SceneManager()
{
	delete actualScene;
}

// Switch between scene's Loop
void SceneManager::Update()
{
	SwitchScene();
	PhysicsManager::GetInstance()->Update();
	GameMaster::GetInstance()->Purge();
	actualScene->Update();
}

// Function for switch between all scenes
void SceneManager::SwitchScene()
{
	if (indexScene != GameMaster::GetGameData().indexScene)
	{
		indexScene = GameMaster::GetGameData().indexScene;

		switch (indexScene)
		{
		case Scene::MENU:
			actualScene = new Menu();
			break;
		case Scene::LOBBY:
			actualScene = new Lobby();
			break;
		case Scene::INGAME:
			actualScene = new InGame();
			break;
		}
	}
}