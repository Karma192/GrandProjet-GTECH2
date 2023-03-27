#include "Lobby.hpp"

Lobby::Lobby() {
	collisionmanager.addObject(&room);
	collisionmanager.addObject(&e);
	collisionmanager.addObject(&p);
	collisionmanager.addObject(&object);

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
	object.Render();
}

