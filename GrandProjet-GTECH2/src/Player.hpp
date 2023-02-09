#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <math.h>
#include "GameObject.hpp"

#define PLAYER_TEXTURE "ressources/sprites/player/idle.png"
#define PLAYER_IDLE {sf::IntRect(0, 0, 54, 52), sf::IntRect(69, 0, 54, 52),sf::IntRect(130, 0, 54, 52), sf::IntRect(195, 0, 54, 52) }


class Player : public GameObject {
public:
	Player();
	virtual ~Player();


	virtual void Loop()override;
	virtual void Render()override;

	//Player HUD 
	void playerEndurance();
	void playerRegenEndurance();
	void playerUI();


	//Player controller
	void CubeTest();
	void ControllerMove();
	void MovePlayer();
	void KeyboardMove();
	void setCamera();

	void setPv(int pv) { m_pv = pv; }
	int getPv() const { return m_pv; }
	void setAttack(int attack) { m_attack = attack; }
	int getAttack() const { return m_attack; }

	//Player attributes
	int GetPlayerXPos();
	int GetPlayerYPos();

	//Player attack
	void PlayerAttack();
	void PlayerBasicAttack();

	sf::Clock cdBasicAttack;
	sf::RectangleShape hitboxTest;


	//Player draw
	sf::RectangleShape cube;
	sf::Vector2f moveSpeed;
	sf::View view;

	bool IsAttacking = false;

	
protected:
	float endurancePlayer = 100;
	float cd_Endurance = endurance.getElapsedTime().asSeconds();

private:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;


	//Player attack basic
	bool isActtk = true;
	bool asAttacked = false;

	//rectangle pour endurance + vie
	sf::RectangleShape enduranceBar;
	sf::RectangleShape enduranceBarBack;
	sf::RectangleShape lifeBar;

	//cercle pour ulti + spell
	sf::CircleShape playerUltiUI;
	sf::CircleShape playerFirstSpell;
	sf::CircleShape playerSecondSpell;
	sf::CircleShape playerThirdSpell;


	int m_pv;
	int m_attack;
	int playerSpeed = 120;
	sf::Clock endurance;
};