#include <stdio.h>

class Spawner 
{
public:
	virtual ~Spawner();

	void SetQuantity(int);
	void SetMilesStones(float maxX, float minX, float maxY, float minY);
	void TriggerSpawn();

private:
	int quantity = 0;
	
	struct Vector2 
	{
		float x;
		float y;

		Vector2(float valuex, float valuey) { x = valuex; y = valuey; }
	};
};