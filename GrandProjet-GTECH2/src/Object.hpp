#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <cstdlib>
#include "GameObject.hpp"
#include "Player.hpp"

class Object : public GameObject
{
public:
	Object();
	virtual ~Object();

	virtual void Loop()override;
	virtual void Render()override;

	bool collidesWith(CollisionObject* other) override;
	void handleCollision(CollisionObject* other) override;

	int randomX;
	int randomY;
	sf::RectangleShape randomPosObject;
	sf::RectangleShape randomPosObject2;

private:
	bool StopDraw = false;
};

