#include  "InGame.hpp"

InGame::InGame() {
	e = new Enemies();
	p = new Player();
	map = new MapGenerator();

	GameMaster::GetInstance()->SetCollisionManager(&collisionmanager);

	collisionmanager.addObject(&_door);
	collisionmanager.addObject(&sp);
	collisionmanager.addObject(e);
	collisionmanager.addObject(p);
	collisionmanager.addObject(map);

	//collisionmanager.addObject(&object);

	sf::Texture texture;
	texture.create(1, 1);
	texture.loadFromFile("ressources/sprites/player/idle.png");

	_door.CreateDoors(sf::Sprite(texture), 500, 0);
	_door.CreateDoors(sf::Sprite(texture), 900, 300);
	_door.CreateDoors(sf::Sprite(texture), 500, 600);
	_door.CreateDoors(sf::Sprite(texture), 0, 300);
}

InGame::~InGame()
{
}

void InGame::Loop() {
	collisionmanager.updateCollisions();
	p->Loop();
	sp.Loop();
	if (e->_destructed == false)
		e->Loop();
	_door.Loop();
}

void InGame::Render() {
	map->Render();
	p->Render();
	sp.Render();
	if (e->_destructed == false)
		e->Render();
	_door.Render();
}