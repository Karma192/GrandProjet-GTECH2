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
	//AddToScene(sp, 1);
}

Lobby::~Lobby()
{
	delete p;
	delete e;
	delete map;
	//delete sp;
}

void Lobby::Init()
{
	Camera::GetInstance()->SetFollow(p->Sprite());
}
