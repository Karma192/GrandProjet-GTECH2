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
    p.Render();
}