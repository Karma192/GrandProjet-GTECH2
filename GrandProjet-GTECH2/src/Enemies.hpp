#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Player.hpp"

class Enemies : public GameObject
{
public:
	Enemies() = default;
	Enemies(Player*);
	~Enemies();
	virtual void Loop()override;
	virtual void Render()override;

	void Cube2Test();

	void FollowTarget(bool);

	void EnemyMove();

	void GetStunned();

	sf::RectangleShape cube2;
	sf::Clock clock2;

	Player* contextPlayer;

	GameObject* target;

	bool follow = false;
	bool IsFixed = true;

private:
	//void EnemyTest();
	float followRadius = 1.f;
	sf::Texture enemiesTexture;
	sf::Sprite enemiesSprite;

};