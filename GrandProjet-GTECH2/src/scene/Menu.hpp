#pragma once
#include "Scene.hpp"
#include "../GameObject/menuHUD.h"


class Menu : public GameScene {
public:
	Menu();
	virtual ~Menu();

	virtual void Init()override;

	menuHUD* menuhud;
};