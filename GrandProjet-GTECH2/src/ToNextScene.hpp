#pragma once

#include <iostream>
#include "GameObject.hpp"
#include "Player.hpp"

class ToNextScene : public GameObject
{
public:
	ToNextScene();
	ToNextScene(int, sf::Sprite, int, int);
	virtual ~ToNextScene();

	void Loop()override;
	void Render()override;

	sf::Sprite _sprite;
private:
	int scene;

	void GoToScene();
};