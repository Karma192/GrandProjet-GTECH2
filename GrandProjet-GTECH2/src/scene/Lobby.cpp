#include "Lobby.hpp"

Lobby::Lobby() {
    p = new Player();
    AddToScene(*p, 0);
    e = new Enemies(p);
    AddToScene(*e, 0);
}

Lobby::~Lobby() 
{
    delete p, e;
}

void Lobby::Loop() {
    p->Loop();
    e->Loop();
}

void Lobby::Render() {
    //Background();
    p->Render();
    e->Render();
}

void Lobby::Background() {
    menuBackground.loadFromFile("ressources/background.jpg");
    menuBckSprite.setTexture(menuBackground);
    gameData.window->draw(menuBckSprite);
}