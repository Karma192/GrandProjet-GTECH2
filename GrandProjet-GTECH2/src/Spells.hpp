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

private:

	Vector2f playerCenter;
	Vector2f mousePosWindow;
	Vector2f aimDir;
	Vector2f aimDirNorm;

	float _mousePos;
	sf::Vector2f launchDirection;
	float speed = 10;
	float PlayerRotation;
	bool launched = true;
};

