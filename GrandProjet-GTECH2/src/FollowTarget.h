#pragma once
#include "Player.hpp"
#include "Enemies.hpp"
#include "GameObject.hpp"


class FollowTarget : public GameObject
{
public:
	FollowTarget();
	~FollowTarget();

	virtual void Loop()override;
	virtual void Render()override;

	void AggroSystem();

	sf::Vector2f TargetPos;
	sf::Vector2f RelatPos;
	sf::Clock ClockMove;
	sf::Time Frame;
	sf::Vector2f FollowPos;

	Player* contextPlayer;
	Enemies* contextEnemy;

	int distance;
	bool follow;

private:

};

