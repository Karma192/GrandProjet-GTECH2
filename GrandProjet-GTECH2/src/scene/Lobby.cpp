#include "Lobby.hpp"
#include "../Instance/Camera.hpp"

Lobby::Lobby() 
{
	map = new MapGenerator();
	AddToScene(map, 0);
 	p = new Player();
	AddToScene(p, 1);
	e = new Enemies();
	AddToScene(e, 1);
	//sp = new Spells();
}

Lobby::~Lobby()
{
	delete p;
	delete e;
	delete map;
	//delete sp;
}

Player* Lobby::GetPlayer() 
{
	return p;
}

