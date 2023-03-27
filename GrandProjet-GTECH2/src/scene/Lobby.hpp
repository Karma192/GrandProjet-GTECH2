#pragma once
#include "Scene.hpp"
#include "../Player.hpp"
#include "../Enemies.hpp"
#include "../MapGenerator.hpp"
#include "../Object.hpp"
#include "../CollisionManager.h"
#include "../BasicAttack.hpp"

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
    BasicAttack ba;
    MapGenerator _map;
    Room room;
    CollisionManager collisionmanager;
    
    void Background();
    sf::Texture menuBackground;
    sf::Sprite menuBckSprite;
};