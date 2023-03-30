#pragma once
#include "Scene.hpp"
#include "../GameObject/menuHUD.h"


class Menu : public GameScene {
public:
	Menu();
	virtual ~Menu();

	menuHUD menuhud;

	virtual void Loop()override;
	virtual void Render()override;

private:
};