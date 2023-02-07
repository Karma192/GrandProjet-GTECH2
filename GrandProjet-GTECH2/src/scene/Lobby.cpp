#include "Lobby.hpp"

Lobby::Lobby() {
    AddToScene(map, 0);
    AddToScene(p, 1);
}

Lobby::~Lobby() {

}

void Lobby::Loop() {
    p.Loop();
}

void Lobby::Render() {
    //Background();
    p.Render();
}

void Lobby::Background() {
    /*menuBackground.loadFromFile("ressources/background.jpg");
    menuBckSprite.setTexture(menuBackground);
    gameData.window->draw(menuBckSprite);*/
    map.Render();
}