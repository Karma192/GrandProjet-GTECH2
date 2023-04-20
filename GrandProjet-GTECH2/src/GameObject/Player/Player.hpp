#pragma once 

#define M_PI           3.14159265358979323846  /* pi */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <cmath>
#include "../GameObject.hpp"
#include "../Enemies.hpp"
#include "../../MapGenerator.hpp"
#include "../ToNextScene.hpp"
#include "Spells.hpp"

class Player : public GameObject 
{
public:
	Player();
	virtual ~Player();

	virtual void Loop()override;
	virtual void Render()override;

	virtual void OnCollisionEnter(PhysicBody* other)override;

	//Player HUD 
	void playerUI();

	//Player controller
	void MouseUsage();
	void ControllerMove();
	void MovePlayer();
	void KeyboardMove();

	//Player attributes
	void setPv(int pv) { m_pv = pv; }
	int getPv() const { return m_pv; }
	void setAttack(int attack) { m_attack = attack; }
	int getAttack() const { return m_attack; }

	int GetPlayerXPos();
	int GetPlayerYPos();
	int getPlayerSpeed();
	void setPlayerSpeed(float);

	//Player attack
	void PlayerAttack();
	void PlayerBasicAttack();

	sf::Clock cdBasicAttack;
	sf::RectangleShape hitboxTest;

	//Player draw
	sf::Vector2f moveSpeed;
	sf::View view;
	float rotation;
	sf::Vector2f velocity;
	sf::FloatRect CubeBounds;

	bool IsAttacking = false;

protected:
	float endurancePlayer = 100;
	float cd_Endurance = endurance.getElapsedTime().asSeconds();

private:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Clock clock;
	sf::IntRect rectSprite;

	sf::Vector2i _mousePos;
	sf::Vector2f _playerCenter;
	sf::Vector2f _worldPosition;
	sf::Vector2f _aimDir;
	float _aimDirNorm;
	float angleDegrees;

	//Player attack basic
	bool _dashing = false;
	bool isActtk = true;
	bool asAttacked = false;


	//Dashing
	int BoostSpeed;

	//rectangle pour endurance + vie
	sf::RectangleShape enduranceBar;
	sf::RectangleShape enduranceBarBack;
	sf::RectangleShape lifeBar;

	//cercle pour ulti + spell
	sf::CircleShape playerUltiUI;
	sf::CircleShape playerFirstSpell;
	sf::CircleShape playerSecondSpell;
	sf::CircleShape playerThirdSpell;

	sf::CircleShape playerUITab[4];


	int playerHP; 
	int m_pv;
	int m_attack;
	int playerSpeed = 20;
	sf::Clock endurance;

	bool lookingLeft = false;

	int _playerDirection = 0;
	bool _stopMoving = false;
	int _wallTouched = 0;

	bool _collideUp;
	bool _collideDown;
	bool _collideLeft;
	bool _collideRight;
};