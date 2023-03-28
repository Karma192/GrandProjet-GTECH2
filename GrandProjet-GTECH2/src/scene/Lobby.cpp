#include "Lobby.hpp"
#include "../Camera.hpp"

Lobby::Lobby() {
	collisionmanager.addObject(&map);
	collisionmanager.addObject(&sp);
	collisionmanager.addObject(&e);
	collisionmanager.addObject(&p);
	//collisionmanager.addObject(&object);
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
	Camera::GetInstance()->SetFollow(&p.cube);
	collisionmanager.updateCollisions();
	p.Loop();
	sp.Loop();
	e.Loop();
	_door.Loop();
}

void Lobby::Render() {
	map.Render();
	p.Render();
	sp.Render();
	e.Render();
	_door.Render();
	//object.Render();
}

