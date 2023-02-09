#pragma once
#include "Scene.hpp"
#include "../Player.hpp"
#include "../Enemies.hpp"
#include "../MapGenerator.hpp"

class Lobby : public GameScene {
public:
    Lobby();
    virtual ~Lobby();

    virtual void Loop()override;
    virtual void Render()override;

private:
    Player* p;
    Enemies* e;
    MapGenerator* map;
    

    void Background();
    sf::Texture menuBackground;
    sf::Sprite menuBckSprite;
};