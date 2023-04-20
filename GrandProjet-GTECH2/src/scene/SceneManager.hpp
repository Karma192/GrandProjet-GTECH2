#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "../Instance/GameMaster.hpp"
#include "../Instance/PhysicsManager.hpp"
#include "Menu.hpp"
#include "Lobby.hpp"
#include "InGame.hpp"



class SceneManager {
public:

	SceneManager();
	virtual ~SceneManager();

	void Update();

private:
	int indexScene = 0;

	GameScene* actualScene;

	void SwitchScene();
};