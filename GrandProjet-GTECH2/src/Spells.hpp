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

	void SetFireBall(Player& player);

	void Update();
	void Launch(Vector2f StartPos,Vector2f LaunchDir);
	void DrawSpell();

	bool isLaunched() { return launched; }
	void reset(){ launched = false; }

	sf::CircleShape spell;

private:
	sf::Vector2f position;
	sf::Vector2f direction;
	float speed;
	bool launched;
};

