#include "Lobby.hpp"

Lobby::Lobby() {
	collisionmanager.addObject(&sp);
	collisionmanager.addObject(&p);
	collisionmanager.addObject(&e);
	collisionmanager.addObject(&object);
}

Lobby::~Lobby()
{
}

void Lobby::Loop() {
	collisionmanager.updateCollisions();
	room.Loop();
	p.Loop();
	sp.Loop();
	e.Loop();
}

void Lobby::Render() {
	map.Render();
	p.Render();
	sp.Render();
	e.Render();
	object.Render();
}

