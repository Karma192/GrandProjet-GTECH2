#pragma once
#include <iostream>
#include "Scene.hpp"
#include "../Player.hpp"
#include "../Enemies.hpp"
#include "../MapGenerator.hpp"
#include "../Object.hpp"
#include "../Doors.hpp"
#include "../Spells.hpp"
#include "../CollisionManager.h"
#include "../ToNextScene.hpp"

class InGame : public GameScene {
public:
	InGame();
	virtual ~InGame();

	virtual void Loop()override;
	virtual void Render()override;

private:
    Player* p;
    //Object object;
    Enemies* e;
    Spells sp;
    MapGenerator* map;
    ToNextScene _door;
    CollisionManager collisionmanager;

    sf::Texture menuBackground;
    sf::Sprite menuBckSprite;
};