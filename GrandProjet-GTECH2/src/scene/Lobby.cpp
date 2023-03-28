#include "Lobby.hpp"

Lobby::Lobby() {
	collisionmanager.addObject(&e);
	collisionmanager.addObject(&p);
	collisionmanager.addObject(&map);
	collisionmanager.addObject(&object);

}

Lobby::~Lobby()
{
}

void Lobby::Loop() {
	collisionmanager.updateCollisions();
	p.Loop();
	e.Loop();
}

void Lobby::Render() {
	map.Render();
	p.Render();
	e.Render();
	object.Render();
}

