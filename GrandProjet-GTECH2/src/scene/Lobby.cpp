#include "Lobby.hpp"

Lobby::Lobby() {
    AddToScene(p, 0);
}

Lobby::~Lobby() {

}

void Lobby::Loop(sf::Event* event) {
    p.PlayerLoop();
}

void Lobby::Render(sf::RenderWindow* window) {
    p.PlayerTest(window);
}