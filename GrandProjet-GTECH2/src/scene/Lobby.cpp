#include "Lobby.hpp"

Lobby::Lobby() {
	collisionmanager.addObject(&ba);
	collisionmanager.addObject(&p);
	collisionmanager.addObject(&e);
	collisionmanager.addObject(&object);

	//std::cout << "Nombre de layers : " << _map._wallet.GetRoom(0)->map.getLayers().size() << std::endl;
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

void Lobby::Render() 
{
	_map.Render();
	p.Render();
	e.Render();
	object.Render();
}

