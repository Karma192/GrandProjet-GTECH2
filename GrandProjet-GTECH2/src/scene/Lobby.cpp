#include "Lobby.hpp"

Lobby::Lobby() {
	e = new Enemies();
	p = new Player();
	map = new MapGenerator();


	GameMaster::GetInstance()->SetCollisionManager(&collisionmanager);

	collisionmanager.addObject(map);
	collisionmanager.addObject(&sp);
	collisionmanager.addObject(e);
	collisionmanager.addObject(p);
	
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
	collisionmanager.updateCollisions();
	p->Loop();
	sp.Loop();
	if (e->_destructed == false)
		e->Loop();
	_door.Loop();
}

void Lobby::Render() {
	map->Render();
	p->Render();
	sp.Render();
	if ( e->_destructed == false)
		e->Render();
	_door.Render();
}

