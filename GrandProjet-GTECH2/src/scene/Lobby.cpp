#include "Lobby.hpp"

Lobby::Lobby() {
    e = new Enemies(&p);
    AddToScene(&p, 0);
    AddToScene(e, 1);
}

Lobby::~Lobby() {

}

void Lobby::Loop() {
    p.Loop();
    po.SetPtr(&p.cube,&e->cube2);
    object.Loop();
    po.Loop();
    e->Loop();
}

void Lobby::Render()
{
    p.Render();
    object.Render();
    //Background();
    e->Render();
}

void Lobby::Background() {
    menuBackground.loadFromFile("ressources/background.jpg");
    menuBckSprite.setTexture(menuBackground);
    gameData.window->draw(menuBckSprite);
}