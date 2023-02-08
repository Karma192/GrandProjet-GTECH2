#include "Lobby.hpp"

Lobby::Lobby() {
    p = Player();
    e = new Enemies(&p);
    po = PhysicsObject(&p);
    AddToScene(&p, 0);
    AddToScene(e, 1);
}

Lobby::~Lobby() {
    delete e;
}

void Lobby::Loop() {
    p.Loop();
    po.SetPtr(&p.cube,&e->cube2,&p.hitboxTest);
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