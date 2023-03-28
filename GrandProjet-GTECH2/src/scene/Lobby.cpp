#include "Lobby.hpp"

Lobby::Lobby() {
	collisionmanager.addObject(&p);
	collisionmanager.addObject(&e);
	collisionmanager.addObject(&object);
	collisionmanager.addObject(&_door);

	sf::Texture texture;
	texture.create(1, 1);
	texture.loadFromFile("ressources/sprites/player/idle.png");
	_door = ToNextScene(0, sf::Sprite(texture),1 ,1);
}

Lobby::~Lobby()
{
}

void Lobby::Loop() {
	collisionmanager.updateCollisions();
	room.Loop();
	p.Loop();
	e.Loop();
	_door.Loop();
}

void Lobby::Render() {
	map.Render();
	p.Render();
	e.Render();
	_door.Render();
	object.Render();
}

