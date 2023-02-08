#include "Lobby.hpp"

Lobby::Lobby() {
    AddToScene(p, 0);
    
}

Lobby::~Lobby() {

}

void Lobby::Loop() {
    p.Loop();
    po.SetPtr(&p.cube);
    object.Loop();
    po.Loop();
}

void Lobby::Render() 
{
    p.Render();
    object.Render();
    //Background();
}

void Lobby::Background() {
    menuBackground.loadFromFile("ressources/background.jpg");
    menuBckSprite.setTexture(menuBackground);
    gameData.window->draw(menuBckSprite);
}