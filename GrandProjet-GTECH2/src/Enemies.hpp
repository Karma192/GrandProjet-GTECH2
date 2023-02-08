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

private:
	//void EnemyTest();

	sf::Texture enemiesTexture;
	sf::Sprite enemiesSprite;

};