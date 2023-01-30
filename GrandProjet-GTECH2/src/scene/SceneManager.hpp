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
	sf::RenderWindow* window;
	sf::Event* event;

	Menu menu;
	Lobby lobby;
	InGame ingame;


	SceneManager();
	virtual ~SceneManager();

	void SetSM(sf::RenderWindow*, sf::Event*);
	void Update();

private:
	void SwitchScene();
};