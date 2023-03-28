#pragma once
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "PhysicsManager.hpp"

class PhysicBody
{
private:
	sf::FloatRect _hitbox;
	std::string _tag;
public:
	PhysicBody();

	sf::FloatRect* Hitbox() { return &_hitbox; }

	virtual void OnCollisionEnter(PhysicBody* other);
	void SetHitbox(sf::Vector2f coord, sf::Vector2f size);
	void SetCollideTag(std::string tag);
	bool CompareTag(std::string tag);
};