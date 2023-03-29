#pragma once
#include "Scene.hpp"
#include "../Player.hpp"
#include "../Enemies.hpp"
#include "../MapGenerator.hpp"
#include "../Object.hpp"
#include "../Doors.hpp"
#include "../Spells.hpp"
#include "../CollisionManager.h"
#include "../ToNextScene.hpp"

class Lobby : public GameScene {
public:
    Lobby();
    virtual ~Lobby();

    virtual void Loop()override;
    virtual void Render()override;

private:
    Player p;
    //Object object;
    Enemies e;
    Spells sp;
    MapGenerator map;
    Room room;
    
    sf::Texture menuBackground;
    sf::Sprite menuBckSprite;
};