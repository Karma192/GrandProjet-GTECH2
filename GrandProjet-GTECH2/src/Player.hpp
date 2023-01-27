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

	void PlayerLoop();
	void PlayerRender(sf::RenderWindow* window);

	//Player HUD 

	void playerEndurance();
	void playerRegenEndurance();
	void playerUI();

	void ControllerInput();

	void ControllerMove();

	void MovePlayer();

	//rectangle pour endurance + vie
	sf::RectangleShape enduranceBar;
	sf::RectangleShape enduranceBarBack;
	sf::RectangleShape lifeBar;

	//cercle pour ulti + spell
	sf::CircleShape playerUltiUI;
	sf::CircleShape playerFirstSpell;
	sf::CircleShape playerSecondSpell;
	sf::CircleShape playerThirdSpell;

	//test
	sf::RectangleShape cube;
	sf::Vector2f moveSpeed;
	int frame = 0;

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

private:
	sf::Clock clock;

};