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
	int MaxCooldownFireBall = 100;
	float speed = 10;

	///For Slide
	void SetSlide();
	int _Speed;
	int DashTime = 0;
	int CooldownDash = 100;
	int Rap = 10;

private:
	Player* player;

	sf::Vector2f position;
	sf::Vector2f direction;
	sf::Vector2f PlayerPos;
	sf::FloatRect PlayerBounds;
	sf::Vector2f launchDirection;
	sf::RectangleShape Cube;
	int PlayerRapidity;
	int PlayerRotation;
	bool launched = true;
};

