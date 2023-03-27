#pragma once
#include "Scene.hpp"
#include "../Player.hpp"
#include "../Enemies.hpp"
#include "../MapGenerator.hpp"
#include "../Object.hpp"
#include "../PhysicsObject.hpp"
#include "../Doors.hpp"
#include "../Spells.hpp"

class Lobby : public GameScene {
public:
    Lobby();
    virtual ~Lobby();

    virtual void Loop()override;
    virtual void Render()override;

private:
    Player* p;
    Spells* sp;
    Object* object;
    PhysicsObject* po;
    Enemies* e;
    MapGenerator* map;
    Doors* exit;
    sf::Texture menuBackground;
    sf::Sprite menuBckSprite;
};