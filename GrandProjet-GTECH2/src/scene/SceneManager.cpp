#include "SceneManager.hpp"

SceneManager::SceneManager() {
	this->event = nullptr;
	this->window = nullptr;
}

SceneManager::~SceneManager() 
{

}

// Set the pointer to give to all scenes
void SceneManager::SetSM(sf::RenderWindow* win, sf::Event* e) 
{
	this->window = win;
	this->event = e;
}

// Switch between scene's Loop
void SceneManager::Update() 
{
	SwitchScene();
}

// Function for switch between all scenes
void SceneManager::SwitchScene() 
{
	switch (smData.indexScene) 
	{
	case MENU:
		menu.Update();
		//std::cout << "C'est le menu !" << std::endl;
		break;

	case LOBBY:
		lobby.Update();
		//std::cout << "C'est le lobby !" << std::endl;
		break;

	case INGAME:
		ingame.Update();
		//std::cout << "C'est le ingame !" << std::endl;
		break;

	default:
		break;
	}
}