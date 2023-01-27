#include "Lobby.hpp"

Lobby::Lobby() {

}

Lobby::~Lobby() {

}

void Lobby::LobbyLoop(sf::Event* event) {
	p.PlayerLoop();
}

void Lobby::LobbyRender(sf::RenderWindow* window) {
	p.PlayerTest(window);
}