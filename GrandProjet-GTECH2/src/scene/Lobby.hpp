#pragma once
#include "Scene.hpp"
#include "../Player.hpp"
#include "../Object.hpp"
#include "../PhysicsObject.hpp"

class Lobby : public GameScene {
public:
    Lobby();
    virtual ~Lobby();

    virtual void Loop()override;
    virtual void Render()override;

private:
    Player p;
    Object object;
    PhysicsObject po;

    void Background();
    sf::Texture menuBackground;
    sf::Sprite menuBckSprite;
};