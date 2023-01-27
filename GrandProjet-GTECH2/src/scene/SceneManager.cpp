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
	case MENU:
		index = MENU;
		break;
	case LOBBY:
		index = LOBBY;
		break;
	case INGAME:
		index = INGAME;
		break;
	default:
		index = MENU;
		break;
	}
}

// Switch between scene's Loop
void SceneManager::SceneManagerLoop() {
	SwitchScene(LOOP);
}

// Switch between scene's Render
void SceneManager::SceneManagerRender() {
	SwitchScene(RENDER);
}

// Function for switch between all scenes loop/render
void SceneManager::SwitchScene(int x) {
	switch (index) {
	case MENU:
		if (x == LOOP) {
			menu.MenuLoop(event);
			//std::cout << "C'est le menu loop !" << std::endl;
		}
		else if (x == RENDER) {
			menu.MenuRender(window);
			//std::cout << "C'est le menu render !" << std::endl;
		}
		break;
	case LOBBY:
		if (x == LOOP) {
			lobby.LobbyLoop(event);
			std::cout << "C'est le lobby loop !" << std::endl;
		}
		else if (x == RENDER) {
			lobby.LobbyRender(window);
			std::cout << "C'est le lobby render !" << std::endl;
		}
		break;
	case INGAME:
		if (x == LOOP) {
			ingame.InGameLoop(event);
			std::cout << "C'est le jeu loop !" << std::endl;
		}
		else if (x == RENDER) {
			ingame.InGameRender(window);
			std::cout << "C'est le jeu render !" << std::endl;
		}
		break;
	default:
		break;
	}
}