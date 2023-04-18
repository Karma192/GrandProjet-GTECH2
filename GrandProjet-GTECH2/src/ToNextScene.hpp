#pragma once

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

	void CreateDoors(sf::Sprite spr, int posx, int posy);

	bool collidesWith(CollisionObject* other) override;
	void handleCollision(CollisionObject* other) override;
	sf::Sprite _sprite;

	int mapIndex;

private:

	std::vector <sf::Sprite> _spritevect;
	int map;
	int scene;
	void GoToScene();
	void ChangeMap();
};