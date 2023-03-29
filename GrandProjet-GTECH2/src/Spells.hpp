#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "GameObject.hpp"
#include "Player.hpp"

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
	int MaxCooldownFireBall = 0;

	///For Slide
	void SetSlide();

	///For third spell
	void ThirdSpell();


private:
	Player* player;

	///Second spell
	sf::Vector2f position;
	sf::Vector2f direction;
	sf::Vector2f PlayerPos;
	sf::FloatRect PlayerBounds;
	sf::Vector2f launchDirection;
	float speed = 10;
	float PlayerRotation;
	bool launched = true;

	///Third Spell
	sf::CircleShape _hitboxThirdSpell;
	int enemyHP; 

};

