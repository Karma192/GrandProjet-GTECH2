#include "Lobby.hpp"

Lobby::Lobby() {
    AddToScene(player, 0);
}

Lobby::~Lobby() {

}

void Lobby::Loop(sf::Event* event) {
    player.Loop(event);
    collision.GetBounds();
}

void Lobby::Render(sf::RenderWindow* window) {
    object.RandomObject(window);
    player.Render(window);
}