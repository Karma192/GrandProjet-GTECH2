#include "SceneManager.hpp"

SceneManager::SceneManager() {
	index = 0;

}

SceneManager::~SceneManager() {

}

void SceneManager::SetSM(sf::RenderWindow* win) {
	this->window = win;
}

void SceneManager::SceneManagerLoop() {
	SwitchScene(0);
}

void SceneManager::SceneManagerRender() {
	SwitchScene(1);
}

// Function which switch between all scenes loop/render
void SceneManager::SwitchScene(int x) {
	switch (index) {
	case MENU :
		if (x == LOOP) {
			menu->MenuLoop();
			std::cout << "C'est le menu loop !" << std::endl;
		}
		else if (x == RENDER) {
			menu->MenuRender();
			std::cout << "C'est le menu render !" << std::endl;
		}
		break;
	case LOBBY :
		if (x == LOOP) {
			lobby->LobbyLoop();
			std::cout << "C'est le lobby loop !" << std::endl;
		}
		else if (x == RENDER) {
			lobby->LobbyRender(window);
			std::cout << "C'est le lobby render !" << std::endl;
		}
		break;
	case INGAME :
		if (x == LOOP) {
			ingame->InGameLoop();
			std::cout << "C'est le jeu loop !" << std::endl;
		}
		else if (x == RENDER) {
			ingame->InGameRender(window);
			std::cout << "C'est le jeu render !" << std::endl;
		}
		break;
	default:
		break;
	}
}