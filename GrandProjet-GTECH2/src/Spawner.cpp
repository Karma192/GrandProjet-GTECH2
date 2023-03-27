#include "Spawner.hpp"
#include "Enemies.hpp"

Spawner::~Spawner()
{
}

void Spawner::SetQuantity(int q)
{
	quantity = q;
}

void Spawner::SetMilesStones(float maxX, float minX, float maxY, float minY)
{
	Vector2 max = Vector2(maxX, maxY);
	Vector2 min = Vector2(minX, minY);
}

void Spawner::TriggerSpawn()
{
	for (int i = 0; i < quantity; i++)
	{
		Enemies e = Enemies(); 
		//Need a way to give a position to the object ennemi
		//float posX = (float)std::rand() % max.x + min.x;
		//float posy = (float)std::rand() % max.y + min.y;
		//e.SetPosition(posX, posY);
	}
}
