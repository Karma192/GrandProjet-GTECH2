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

	void MoveBase(bool);


	sf::RectangleShape cube2;

	Player* contextPlayer;

	GameObject* target;

	bool follow = false;
	//bool IsFixed = true;

	int distance;

	sf::Vector2f TargetPos = contextPlayer->cube.getPosition();
	sf::Vector2f FollowPos = cube2.getPosition();
	sf::Vector2f RelatPos = TargetPos - FollowPos;


private:
	//void EnemyTest();

	sf::Texture enemiesTexture;
	sf::Sprite enemiesSprite;

};