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
    e.Render();
}

void Lobby::Background() {
    menuBackground.loadFromFile("ressources/background.jpg");
    menuBckSprite.setTexture(menuBackground);
    gameData.window->draw(menuBckSprite);
}