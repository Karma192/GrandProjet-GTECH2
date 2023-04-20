#include "EnemySpawner.h"

EnemySpawner::EnemySpawner() 
{

}

EnemySpawner::~EnemySpawner()
{
}


void EnemySpawner::Render() 
{
}



void EnemySpawner::spawnEnemies() 
{
	for (const auto& layer : map.getLayers())
	{
		if (layer->getType() == tmx::Layer::Type::Tile)
		{
			for (unsigned int x = 0; x < map.getTileCount().x; x++)
			{
				for (unsigned int y = 0; y < map.getTileCount().y; y++)
				{
					unsigned int tileID = Layers.getTiles()[x + y * map.getTileCount().x].ID;

					if (tileID == 1)
					{
						std::cout << "Enemy Spawned" << std::endl;
					}

				}
			}
		}
	}
}

void EnemySpawner::createEnemy(unsigned int x, unsigned int y)
{
	//Enemy enemy;
	//enemy.setPosition(x, y);
	//enemies.push_back(enemy);
}

bool EnemySpawner::isEnemyTile(unsigned int tileID)
{
	return tileID == 1;

}
