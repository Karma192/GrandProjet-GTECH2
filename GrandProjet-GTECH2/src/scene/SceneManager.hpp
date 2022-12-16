#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "Lobby.hpp"
#include "InGame.hpp"


class SceneManager {
public:
	int index;

	sf::RenderWindow* window;

	Menu* menu;
	Lobby* lobby;
	InGame* ingame;


	SceneManager();
	virtual ~SceneManager();

	void SetSM(sf::RenderWindow*);
	void SceneManagerLoop();
	void SceneManagerRender();

private:
	enum {
		MENU = 0,
		LOBBY = 1,
		INGAME = 2,
	};

	enum {
		LOOP = 0,
		RENDER = 1,
	};

	void SwitchScene(int);
};