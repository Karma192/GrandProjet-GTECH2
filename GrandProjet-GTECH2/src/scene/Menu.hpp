#pragma once
#include "Scene.hpp"
#include "../Player.hpp"
#include "../Collision.h"
#include "../Enemies.hpp"

class Menu : public Scene {
public:
	Menu();
	virtual ~Menu();

	Collision collision;

	void MenuLoop(sf::Event*);
	void MenuRender(sf::RenderWindow*);


private:
	Player* player;
	Enemies* enemies;
};