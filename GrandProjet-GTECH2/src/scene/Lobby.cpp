#include "Lobby.hpp"

Lobby::Lobby() {
	/*e = new Enemies();
	p = new Player();
	map = new MapGenerator();

	sf::Texture texture;
	texture.create(1, 1);
	texture.loadFromFile("ressources/sprites/player/idle.png");
	_door = ToNextScene(0, sf::Sprite(texture),1 ,1);*/
}

Lobby::~Lobby()
{
}

void Lobby::Loop() {
	p.Loop();
	sp.Loop();
	e.Loop();
	//_door.Loop();
}

void Lobby::Render() {
	map->Render();
	p->Render();
	sp.Render();
	e.Render();
	//_door.Render();
	//object.Render();
}

