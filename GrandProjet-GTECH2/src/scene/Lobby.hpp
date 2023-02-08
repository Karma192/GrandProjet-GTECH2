#pragma once
#include "Scene.hpp"
#include "../MapTest.hpp"
#include "../Player.hpp"
#include "../Enemies.hpp"

class Lobby : public GameScene {
public:
    Lobby();
    virtual ~Lobby();

    virtual void Loop()override;
    virtual void Render()override;

private:
    Player* p;
    Enemies* e;
    Map map;

    void Background();
    sf::Texture menuBackground;
    sf::Sprite menuBckSprite;
};