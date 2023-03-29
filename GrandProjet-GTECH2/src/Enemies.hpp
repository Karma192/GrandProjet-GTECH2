#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Player.hpp"
#include "Object.hpp"
#include "GameMaster.hpp"

class Enemies : public GameObject
{
public:
	Enemies();
	~Enemies();

	virtual void Loop()override;
	virtual void Render()override;

	virtual void OnCollisionEnter(PhysicBody* other)override;

	void Cube2Test();
	void FollowTarget(bool);
	void GetStunned();

	sf::RectangleShape cube2;
	sf::Clock clock2;

	GameObject* target;

	bool follow = false;
	bool IsFixed = true;

	int distance;

private:
	//void EnemyTest();

	int ennemieHP; 

	sf::Texture enemiesTexture;
	sf::Sprite enemiesSprite;
	sf::Vector2f TargetPos;
	//Object object;
};