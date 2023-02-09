#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "Player.hpp"

#define ENEMY_TEXTURE "ressources/sprites/Centipede/Centipede_idle.png"

class Enemies : public GameObject
{
public:
	Enemies() = default;
	Enemies(Player*);
	~Enemies();
	virtual void Loop()override;
	virtual void Render()override;

	//Init Eney
	void Cube2Test();
	sf::Sprite Enemy;
	sf::Texture texture;
	sf::IntRect image;

	void FollowTarget(bool);

	sf::RectangleShape cube2;
	sf::IntRect enemy;

	Player* contextPlayer;

	GameObject* target;

	bool follow = false;
	bool IsFixed = true;

	int distance;

	//For Move
	sf::Vector2f TargetPos;
	sf::Vector2f RelatPos;
	sf::Clock ClockMove;
	sf::Time Frame;
	sf::Vector2f FollowPos;

	float interMove;
	int randDir;

private:
	//void EnemyTest();
	sf::Texture enemiesTexture;
	sf::Sprite enemiesSprite;

};