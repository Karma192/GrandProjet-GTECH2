#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Player.hpp"
#include "Object.hpp"
#include "Animation.h"

class Enemies : public GameObject
{
public:
	Enemies();
	~Enemies();

	virtual void Loop()override;
	virtual void Render()override;

	bool collidesWith(CollisionObject* other) override;
	void handleCollision(CollisionObject* other) override;

	void DisplaySlime();
	void FollowTarget(bool);
	void GetStunned();
	sf::Sprite enemySlime;
	sf::Clock clock2;

	GameObject* target;

	bool follow = false;
	bool IsFixed = true;

	int distance;

private:
	//void EnemyTest();

	int ennemieHP; 

	Animation animationSlime;
	
	sf::Vector2f TargetPos;
	//Object object;
};