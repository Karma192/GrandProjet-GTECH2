#pragma once
#include "Scene.hpp"
#include "../Player.hpp"

class Lobby : public GameScene {
public:
    Lobby();
    virtual ~Lobby();

    virtual void Loop(sf::Event*)override;
    virtual void Render(sf::RenderWindow*)override;

private:
    Player p;
};