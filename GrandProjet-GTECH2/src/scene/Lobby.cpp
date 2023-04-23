#include "Lobby.hpp"
#include "../Instance/Camera.hpp"

Lobby::Lobby() 
{
 	p = new Player();
	AddToScene(p, 1);
	e = new Enemies(p);
	AddToScene(e, 1);
	map = new MapGenerator();
	AddToScene(map, 0);
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
	Camera::GetInstance()->SetFollow(&p->Sprite());
}
