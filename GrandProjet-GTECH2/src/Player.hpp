#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <cmath>
#include "GameObject.hpp"
#include "Enemies.hpp"
#include "GameMaster.hpp"
#include "MapGenerator.hpp"
# define M_PI           3.14159265358979323846  /* pi */


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


	//Player controller
	void CubeTest();
	void MouseUsage();
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
	float rotation;
	sf::Vector2f velocity;
	sf::FloatRect CubeBounds = cube.getLocalBounds();


	bool IsAttacking = false;

protected:
	float endurancePlayer = 100;
	float cd_Endurance = endurance.getElapsedTime().asSeconds();

private:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	sf::Vector2i _mousePos;
	sf::Vector2f _playerCenter;
	sf::Vector2f _worldPosition;
	sf::Vector2f _aimDir;
	float _aimDirNorm;
	float angleDegrees;

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

	int _playerDirection = 0;
	bool _stopMoving = false;
	int _wallTouched = 0;

	bool _collideUp;
	bool _collideDown;
	bool _collideLeft;
	bool _collideRight;
};