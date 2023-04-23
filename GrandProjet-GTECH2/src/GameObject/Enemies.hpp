#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "../GameObject/Player/Player.hpp"
#include "../GameObject/PhysicBody.hpp"
#include "../Instance/GameMaster.hpp"
#include "Animation.h"

class Enemies : public GameObject
{
public:
	Enemies() = default;
	Enemies(GameObject*);
	virtual ~Enemies();

	virtual void Init()override;

	virtual void Loop()override;
	virtual void Render()override;

	virtual void OnCollisionEnter(PhysicBody* other)override;

	// Fonction de suivi de la cible
	void FollowTarget();
	void GetStunned();

	int GetEnemieHP() { return ennemieHP; }
	void SetEnemieHP(int damage) { damage = ennemieHP; }

	sf::Clock clock2;

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
	GameObject* _target;

	int ennemieHP; 
	sf::Texture enemiesTexture;
	sf::Sprite enemiesSprite;
	sf::Vector2f TargetPos;
};