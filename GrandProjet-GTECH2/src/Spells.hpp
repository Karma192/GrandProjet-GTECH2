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

	void SetFireBall();

	void Update();
	void Launch(Vector2f StartPos,Vector2f LaunchDir);
	void DrawSpell();

	bool isLaunched() { return launched; }
	void reset(){ launched = false; }

	sf::CircleShape spell;

private:
	sf::Vector2f position;
	sf::Vector2f direction;
	sf::Vector2f PlayerPos;
	sf::FloatRect PlayerBounds;
	sf::Vector2f launchDirection;
	float speed = 10;
	float playerRotation;
	bool launched = true;
};

