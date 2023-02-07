#include "Lobby.hpp"

Lobby::Lobby() {
    AddToScene(p, 0);
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
    menuBackground.loadFromFile("ressources/map.jpg");
    menuBckSprite.setTexture(menuBackground);
    gameData.window->draw(menuBckSprite);
}