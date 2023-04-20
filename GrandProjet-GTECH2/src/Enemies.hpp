#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Player.hpp"
#include "Object.hpp"
#include "Spells.hpp"
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

	void Cube2Test();
	void FollowTarget(bool);
	void GetStunned();

	int GetEnemieHP() { return ennemieHP; }
	void SetEnemieHP(int damage) { damage = ennemieHP; }

	sf::Sprite cube2;
	sf::Clock clock2;

	GameObject* target;

	bool follow = false;
	bool IsFixed = true;

	int distance;

	// Lilian TEST

	Animation animationSlime;

	std::vector<int> frameIndexIdle;
	std::vector<int> frameIndexRun;
	std::vector<int> frameIndexAttack;
	std::vector<int> frameIndexDie;

	// Lilian TEST

private:
	//void EnemyTest();

	int ennemieHP; 
	sf::Texture enemiesTexture;
	sf::Sprite enemiesSprite;
	sf::Vector2f TargetPos;
	//Object object;
};