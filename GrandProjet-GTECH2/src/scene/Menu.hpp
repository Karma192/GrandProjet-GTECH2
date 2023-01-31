#pragma once
#include "Scene.hpp"
#include "../Player.hpp"
#include "../Enemies.hpp"
#include "../menuHUD.h"


class Menu : public GameScene {
public:
	Menu();
	virtual ~Menu();


	virtual void Loop(sf::Event*)override;
	virtual void Render(sf::RenderWindow*)override;

private:
	menuHUD menu;
};