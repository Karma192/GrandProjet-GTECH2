#include "SceneManager.hpp"
#include "../Instance/Camera.hpp"

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
		Camera::GetInstance()->ResetCamera();
		menu.Update();
#ifdef _DEBUG
		//std::cout << "C'est le menu !" << std::endl;
#endif // DEBUG
		break;

	case LOBBY:
		Camera::GetInstance()->SetFollow(lobby.GetPlayer()->Sprite());
		lobby.Update();
		PhysicsManager::GetInstance()->Update();
#ifdef DEBUG
		//std::cout << "C'est le lobby !" << std::endl;
#endif // DEBUG
		break;

	case INGAME:
		Camera::GetInstance()->ResetCamera();
		ingame.Update();
		PhysicsManager::GetInstance()->Update();
#ifdef DEBUG
		//std::cout << "C'est le ingame !" << std::endl;
#endif // DEBUG
		break;

	default:
		break;
	}
}