#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Player.hpp"
#include "Object.hpp"

class Enemies : public GameObject
{
public:
	Enemies();
	~Enemies();

	virtual void Loop()override;
	virtual void Render()override;

	bool collidesWith(CollisionObject* other) override;
	void handleCollision(CollisionObject* other) override;

	void Cube2Test();
	void FollowTarget(bool);
	void MoveBase();
	void EnemyMove();
	void GetStunned();

	sf::RectangleShape cube2;
	sf::Clock clock2;

	GameObject* target;

	bool follow = true;
	bool IsFixed = true;

	int distance;

private:
	//void EnemyTest();
	float followRadius = 1.f;
	sf::Texture enemiesTexture;
	sf::Sprite enemiesSprite;
	sf::Vector2f TargetPos;
};