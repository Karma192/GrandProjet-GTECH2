#include "Lobby.hpp"

Lobby::Lobby() {
	collisionmanager.addObject(&p);
	collisionmanager.addObject(&e);
}

Lobby::~Lobby()
{
}

void Lobby::Loop() {
	collisionmanager.updateCollisions();
	room.Loop();
	p.Loop();
	e.Loop();
}

void Lobby::Render() {
	map.Render();
	p.Render();
	e.Render();
}

