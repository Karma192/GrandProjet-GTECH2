#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <vector>

#define PLAYER_TEXTURE "ressources/sprites/player/idle.png"
#define PLAYER_IDLE {sf::IntRect(0, 0, 54, 52), sf::IntRect(69, 0, 54, 52),sf::IntRect(130, 0, 54, 52), sf::IntRect(195, 0, 54, 52) }


class Player {
public:
	Player();
	virtual ~Player();
	void PlayerLoop();
	void PlayerRender(sf::RenderWindow* window);
	//sf::Clock clock;
	int frame = 0;

private:
	sf::Clock clock;

};