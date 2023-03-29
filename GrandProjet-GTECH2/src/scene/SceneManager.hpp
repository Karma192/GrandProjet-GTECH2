#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "../GameMaster.hpp"
#include "Menu.hpp"
#include "Lobby.hpp"
#include "InGame.hpp"



class SceneManager {
public:
	Menu menu;
	Lobby lobby;
	InGame ingame;

	SceneManager();
	virtual ~SceneManager();

	void Update();

private:
	void SwitchScene();
};