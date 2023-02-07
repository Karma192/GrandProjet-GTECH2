#pragma once
#include "Scene.hpp"
#include "../MapTest.hpp"
#include "../Player.hpp"

class Lobby : public GameScene {
public:
    Lobby();
    virtual ~Lobby();

    virtual void Loop()override;
    virtual void Render()override;

private:
    Player p;
    Map map;

    void Background();
    sf::Texture menuBackground;
    sf::Sprite menuBckSprite;
};