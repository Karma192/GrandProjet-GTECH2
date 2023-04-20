#pragma once
#include <iostream>
#include "src/MapGenerator.hpp"
#include "src/GameObject.hpp"
#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>



class EnemySpawner : public GameObject
{
public :
	EnemySpawner();
	~EnemySpawner();

	void Render();

	void spawnEnemies();

	void createEnemy(unsigned int x, unsigned int y);
	bool isEnemyTile(unsigned int tileID);



private :
	tmx::Map map;
	tmx::Map layer;
	tmx::TileLayer Layers;
};