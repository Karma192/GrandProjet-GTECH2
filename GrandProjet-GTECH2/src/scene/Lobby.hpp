#pragma once
#include "Scene.hpp"
#include "../Player.hpp"

class Lobby : public Scene {
public:
    Lobby();
    virtual ~Lobby();

    void LobbyLoop(sf::Event*);
    void LobbyRender(sf::RenderWindow*);

private:
    Player p;
};