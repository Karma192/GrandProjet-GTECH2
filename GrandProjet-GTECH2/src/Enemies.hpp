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

<<<<<<< Updated upstream
	void MoveBase();

	void EnemyMove();

	void GetStunned();

=======
>>>>>>> Stashed changes
	sf::RectangleShape cube2;
	sf::Clock clock2;

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
	float followRadius = 1.f;
	sf::Texture enemiesTexture;
	sf::Sprite enemiesSprite;

};