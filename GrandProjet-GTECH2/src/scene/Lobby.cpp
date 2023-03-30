#include "Lobby.hpp"

Lobby::Lobby() {
	p = new Player();
	e = new Enemies();
	map = new MapGenerator();
	//sp = new Spells();

	/*sf::Texture texture;
	texture.create(1, 1);
	texture.loadFromFile("ressources/sprites/player/idle.png");
	_door = new ToNextScene(0, sf::Sprite(texture),1 ,1);*/
}

Lobby::~Lobby()
{
}

void Lobby::Loop() {
	p->Loop();
	//sp->Loop();
	e->Loop();
	//_door.Loop();
}

void Lobby::Render() {
	map->Render();
	p->Render();
	//sp->Render();
	e->Render();
	//_door.Render();
	//object.Render();
}

