#pragma once
#include "Scene.hpp"
#include "../Player.hpp"

class Menu : public Scene {
public:
	Menu();
	virtual ~Menu();

	void MenuLoop(sf::Event*);
	void MenuRender(sf::RenderWindow*);

private:
	Player* player;
};