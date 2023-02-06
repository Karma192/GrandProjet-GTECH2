#include "Lobby.hpp"

Lobby::Lobby() {
    AddToScene(p, 0);
}

Lobby::~Lobby() {

}

void Lobby::Loop() {
    p.Loop();
    e.Loop();
}

void Lobby::Render() {
    //Background();
    p.Render();
    p.Render();
}

void Lobby::Background() {
    menuBackground.loadFromFile("ressources/background.jpg");
    menuBckSprite.setTexture(menuBackground);
    gameData.window->draw(menuBckSprite);
}