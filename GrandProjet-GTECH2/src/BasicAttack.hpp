#pragma once

#include "GameObject.hpp"
#include "Player.hpp"
#include "Enemies.hpp"

class BasicAttack : public GameObject 
{
public:
	BasicAttack();
	BasicAttack(sf::RectangleShape*);
	virtual ~BasicAttack();

	virtual void Loop()override;
	virtual void Render()override;

	bool collidesWith(CollisionObject* other) override;
	void handleCollision(CollisionObject*)override;

	void Attack(int x, int y);

private:
	static bool isAttacking;

	int lifeTime = 100;
	sf::Clock cdBasicAttack;
	sf::RectangleShape playerCube;
	sf::RectangleShape hitboxTest;


};