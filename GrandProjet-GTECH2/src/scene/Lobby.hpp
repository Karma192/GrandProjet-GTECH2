#pragma once

#include "Scene.hpp"
#include "../GameObject/Player/Player.hpp"
#include "../GameObject/Enemies.hpp"
#include "../MapGenerator.hpp"
#include "../GameObject/Object.hpp"
#include "../GameObject/Player/Spells.hpp"
#include "../GameObject/ToNextScene.hpp"

class Lobby : public GameScene {
public:
    Lobby();
    virtual ~Lobby();

    Player* GetPlayer();

private:
    Player* p;
    //Object object;
    Enemies* e;
    //Spells* sp;
    MapGenerator* map;
    //ToNextScene* _door;
    
    sf::Texture menuBackground;
    sf::Sprite menuBckSprite;
};