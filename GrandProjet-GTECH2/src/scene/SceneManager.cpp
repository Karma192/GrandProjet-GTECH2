#include "SceneManager.hpp"

SceneManager::SceneManager() {
	index = 0;
}

SceneManager::~SceneManager() {

}

// Set the pointer to give to all scenes
void SceneManager::SetSM(sf::RenderWindow* win, sf::Event* e) {
	this->window = win;
	this->event = e;
}

// Function to call for change active scene
void SceneManager::SetActiveScene(int scene) {
	switch (scene) {
	case MENU :
		index = MENU;
		break;
	case LOBBY :
		index = LOBBY;
		break;
	case INGAME :
		index = INGAME;
		break;
	default:
		index = MENU;
		break;
	}
}

// Switch between scene's Loop
void SceneManager::Update() {
	SwitchScene();
}

// Function for switch between all scenes
void SceneManager::SwitchScene() {
	switch (index) {
	case MENU :
		menu.Update(event, window);
		std::cout << "C'est le menu !" << std::endl;
		break;

	case LOBBY :
		lobby.Update(event, window);
		std::cout << "C'est le lobby !" << std::endl;
		break;

	case INGAME :
		ingame.Update(event, window);
		std::cout << "C'est le ingame !" << std::endl;
		break;

	default:
		break;
	}
}