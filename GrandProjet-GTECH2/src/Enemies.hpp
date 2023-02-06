#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Player.hpp"

class Enemies : public GameObject
{
public:
	Enemies();
	~Enemies();
	virtual void Loop()override;
	virtual void Render()override;

	void Cube2Test();

	void FollowTarget();

	sf::RectangleShape cube2;

private:
	void EnemiesTest();

	sf::Texture enemiesTexture;
	sf::Sprite enemiesSprite;

};