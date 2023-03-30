#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "GameObject.hpp"
#include "Player.hpp"
#include "Enemies.hpp"
#include <chrono>

class Spells : public GameObject
{
public:
	Spells();
	virtual ~Spells();


	virtual void Loop()override;
	virtual void Render()override;

	bool collidesWith(CollisionObject* other) override;
	void handleCollision(CollisionObject* other) override;

	///For FireBall
	void SetFireBall();
	void Launch(sf::Vector2f StartPos,sf::Vector2f LaunchDir);
	void DrawSpell();
	bool isLaunched() { return launched; }

	sf::CircleShape Spell;
	int CooldownFireBall;
	int MaxCooldownFireBall = 100;
	float speed = 10;
	int PlayerRapidity;


	///For Slide
	void SetDash();
	int _Speed;
	bool _canDash = true;
	bool _asDash = false;
	sf::Time DashReset;
	sf::Clock clock;

	///For third spell
	void ThirdSpell();
	int GetThirdSpellDamage() { return thirdSpellDamage;  };
	sf::CircleShape _hitboxThirdSpell;
	int thirdSpellDamage;


private:

	///Second spell
	sf::Vector2f position;
	sf::Vector2f direction;
	sf::Vector2f PlayerPos;
	sf::FloatRect PlayerBounds;
	sf::Vector2f launchDirection;
	sf::RectangleShape Cube;
	int PlayerRotation;
	bool launched = true;


};

