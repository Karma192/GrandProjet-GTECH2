#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Enemies : public GameObject
{
public:
	Enemies();
	~Enemies();
	virtual void Loop()override;
	virtual void Render()override;

private:
	void EnemiesTest();


	sf::Texture enemiesTexture;
	sf::Sprite enemiesSprite;

};