#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <math.h>
#include "GameObject.hpp"
#include "Enemies.hpp"
#include "Animation.h"

class Player : public GameObject {
public:
	Player();
	virtual ~Player();

	virtual void Loop()override;
	virtual void Render()override;

	bool collidesWith(CollisionObject* other) override;
	void handleCollision(CollisionObject* other) override;

	//Player HUD 
	void playerEndurance();
	void playerRegenEndurance();
	void playerUI();

	//Player display
	void DisplayPLayer();

	//Player controller
	void ControllerMove();
	void MovePlayer();
	void Static();
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

	sf::Sprite playerSprite;
	sf::Clock cdBasicAttack;
	sf::RectangleShape hitboxTest;

	bool IsAttacking = false;

	Animation animationIdlePlayer;
	Animation animationRunPlayer;

protected:
	float endurancePlayer = 100;
	float cd_Endurance = endurance.getElapsedTime().asSeconds();

private:
	//Player draw
	sf::Vector2f moveSpeed;
	sf::View view;

	//Animation* animationIdlePlayer;
	//Animation* animationRunPlayer;

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
	int playerSpeed = 20;
	sf::Clock endurance;

	bool lookingLeft = false;
};