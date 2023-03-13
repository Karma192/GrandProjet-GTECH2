#include "Lobby.hpp"

Lobby::Lobby() {
	p = new Player();
	AddToScene(p, 1);
	e = new Enemies(p);
	AddToScene(e, 0);
	//map = new MapGenerator();
	//AddToScene(map, 0);
	exit = new Doors();
	AddToScene(exit, 0);
}

Lobby::~Lobby()
{
	delete p, e, map, exit;
}

void Lobby::Loop() {
	ft.Loop();
	p->Loop();
	e->Loop();
}

void Lobby::Render() {
	//map->Render();
	p->Render();
	e->Render();
	exit->Render();
}

