#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <vector>
#include "GameObject.hpp"

#define PLAYER_TEXTURE "ressources/sprites/player/idle.png"
#define PLAYER_IDLE {sf::IntRect(0, 0, 54, 52), sf::IntRect(69, 0, 54, 52),sf::IntRect(130, 0, 54, 52), sf::IntRect(195, 0, 54, 52) }


class Player : public GameObject {
public:
	Player();
	virtual ~Player();

	virtual void Loop(sf::Event*)override;
	//void PlayerTest(sf::RenderWindow* window);
	virtual void Render(sf::RenderWindow*)override;
	void AnimPlayer(sf::RenderWindow*); // Arthur c'est ton code ici
	int frame = 0;

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

private:
	sf::Clock clock;

};