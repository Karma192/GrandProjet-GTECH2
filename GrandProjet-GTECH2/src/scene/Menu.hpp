#pragma once
#include "Scene.hpp"
#include "../Player.hpp"
#include "../Collision.h"
#include "../Enemies.hpp"
#include "../menuHUD.h"
#include "../Dialogue.h"



class Menu : public Scene {
public:
	Menu();
	virtual ~Menu();

	//Collision collision;

	//virtual void Loop(sf::Event*)override;
	virtual void Render(sf::RenderWindow*)override;


private:
	Player* player;
	menuHUD menu;
	Enemies* enemies;
	Dialogue* dialogue;
};