#pragma once
#include "Scene.hpp"
#include "../menuHUD.h"

class Menu : public Scene {
public:
	Menu();
	virtual ~Menu();

	menuHUD menuhud;

	void MenuLoop(sf::Event*);
	void MenuRender(sf::RenderWindow*);


private:
};