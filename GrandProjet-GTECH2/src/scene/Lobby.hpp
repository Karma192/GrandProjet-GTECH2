#pragma once
#include "Scene.hpp"
#include "../Player.hpp"
#include "../Enemies.hpp"
#include "../MapGenerator.hpp"
#include "../Object.hpp"
#include "../CollisionManager.h"

class Lobby : public GameScene {
public:
    Lobby();
    virtual ~Lobby();

    virtual void Loop()override;
    virtual void Render()override;

private:
    Player p;
    Object object;
    Enemies e;
    MapGenerator map;
    Room room;
    CollisionManager collisionmanager;
    
    sf::Texture menuBackground;
    sf::Sprite menuBckSprite;
};