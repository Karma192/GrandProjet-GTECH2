#include "MapGenerator.hpp"

MapGenerator::MapGenerator() {

}

MapGenerator::~MapGenerator() {

}

void MapGenerator::Loop() {
	genMap();
}

void MapGenerator::Render() {

}

void MapGenerator::attributePlace() {
	//int Posx, Posy;
	//bool exit = false;

	//while (!exit) {
	//	Posx = rand() % H_MAX;
	//	Posy = rand() % W_MAX;

	//	if (map[Posx][Posy] == 0) {
	//		if (map[Posx + 1][Posy] != 0 || map[Posx - 1][Posy] != 0 || map[Posx][Posy + 1] != 0 || map[Posx][Posy - 1] != 0) {
	//			map[Posx][Posy] = place;
	//			place++;
	//			exit = true;
	//		}
	//	}
	//}
}

void MapGenerator::lastRoom()
{
	//int Posx, Posy;
	//bool exit = false;
	//while (!exit)
	//{
	//	Posx = rand() % H_MAX;
	//	Posy = rand() % W_MAX;
	//	if (map[Posx][Posy] == 0)
	//	{
	//		if (map[Posx + 1][Posy] != 0 || map[Posx][Posy + 1] != 0 || map[Posx - 1][Posy] != 0 || map[Posx][Posy - 1] != 0) {
	//			if (map[Posx + 1][Posy] != 1 && map[Posx][Posy + 1] != 1 && map[Posx - 1][Posy] != 1 && map[Posx][Posy - 1] != 1) {
	//				map[Posx][Posy] = 5;
	//				exit = true;
	//			}
	//		}
	//	}
	//}
}







void MapGenerator::maps() {
	//int firstPosx, firstPosy;
	//srand(time(NULL));

	////Première room
	//firstPosx = rand() % H_MAX;
	//firstPosy = rand() % W_MAX;
	//map[firstPosx][firstPosy] = 1;

	////Créer les differents points
	//for (int i = 0; i < NB_ROOMS; i++) {
	//	attributePlace();
	//}

	//lastRoom();

	////Afficher la matrice
	//for (int i = 0; i < H_MAX; i++) {
	//	for (int j = 0; j < W_MAX; j++) {
	//		std::cout << map[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}
}

void MapGenerator::resetAll() {
	//place = 2;
	//for (int i = 0; i < 20; i++) {
	//	for (int j = 0; j < 20; j++) {
	//		map[i][j] = 0;
	//	}
	//}
}

void MapGenerator::mapInit()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[i][j] = '*';
		}

	}
}

void MapGenerator::drawMap()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << map[i][j] << " ";
		}

		std::cout << std::endl;

	}
}
void MapGenerator::genFirstRoom()
{
	int firstPosx = 10;
	int firstPosy = 10;
	srand(time(NULL));

	while (firstPosx == 0 || firstPosx == 10 || firstPosy == 0 || firstPosy == 10)
	{
		firstPosx = rand() % H_MAX;
		firstPosy = rand() % W_MAX;
	}
	map[5][5] = 'F';
	firstRoomX = 5;
	firstRoomY = 5;


}

void MapGenerator::genChestAndMarchandRoom()
{
	int posX, posY;
	int chestOrMarchand;
	int counterRoom = 0;
	srand(time(NULL));
	chestOrMarchand = rand() % 100;
	while (counterRoom != 1)
	{

		posX = rand() % H_MAX;
		posY = rand() % W_MAX;

		if (map[posX][posY] == '*')
		{
			if (map[posX + 1][posY] == 'F' || map[posX][posY + 1] == 'F' || map[posX - 1][posY] == 'F' || map[posX][posY - 1] == 'F' ||
				map[posX + 1][posY] == 'S' || map[posX][posY + 1] == 'S' || map[posX - 1][posY] == 'S' || map[posX][posY - 1] == 'S') {
				if (chestOrMarchand >= 50)
				{
					map[posX][posY] = 'C';
				}
				else
				{
					map[posX][posY] = 'M';
				}
				counterRoom++;
			}

		}
	}

}

void MapGenerator::genHealthRoom()
{
	int posX, posY;
	int health;
	int counterRoom = 0;
	srand(time(NULL));
	health = rand() % 100;
	while (counterRoom != 1)
	{
		if (health > 2)
		{
			counterRoom++;
		}
		else
		{

			posX = rand() % H_MAX;
			posY = rand() % W_MAX;

			if (map[posX][posY] == '*')
			{
				if (map[posX + 1][posY] == 'S' || map[posX][posY + 1] == 'S' || map[posX - 1][posY] == 'S' || map[posX][posY - 1] == 'S' ||
					map[posX + 1][posY] == 'M' || map[posX][posY + 1] == 'M' || map[posX - 1][posY] == 'M' || map[posX][posY - 1] == 'M' ||
					map[posX + 1][posY] == 'C' || map[posX][posY + 1] == 'C' || map[posX - 1][posY] == 'C' || map[posX][posY - 1] == 'C')
				{
					map[posX][posY] = 'V';
					counterRoom++;
				}

			}
		}
	}
}

void MapGenerator::genStandarRoom()
{
	int posX, posY;
	int counterRoom = 0;
	srand(time(NULL));

	while (counterRoom != NB_ROOMS)
	{

		posX = rand() % H_MAX;
		posY = rand() % W_MAX;

		if (map[posX][posY] == '*')
		{
			if (map[posX + 1][posY] == 'F' || map[posX][posY + 1] == 'F' || map[posX - 1][posY] == 'F' || map[posX][posY - 1] == 'F' ||
				map[posX + 1][posY] == 'S' || map[posX][posY + 1] == 'S' || map[posX - 1][posY] == 'S' || map[posX][posY - 1] == 'S') {
				map[posX][posY] = 'S';
				counterRoom++;
			}

		}
	}

}
void MapGenerator::genBossRoom()
{


	int lastRoomX = 0;
	int lastRoomY = 0;
	int calculDistX = 0;
	int calculDistY = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 'S')
			{
				if (i > firstRoomX)
				{
					calculDistX = i - firstRoomX;
				}
				else
				{
					calculDistX = firstRoomX - i;
				}
				if (j > firstRoomY)
				{
					calculDistY = j - firstRoomY;
				}
				else
				{
					calculDistY = firstRoomY - j;
				}

				if (calculDistX > lastRoomX)
				{
					lastRoomX = i;
				}
				if (calculDistY > lastRoomY)
				{
					lastRoomY = j;
				}

			}
		}
	}
	map[lastRoomX][lastRoomY] = 'B';

}

void MapGenerator::genPariRoom()
{
	int posX, posY;
	int pari;
	int counterRoom = 0;
	srand(time(NULL));
	pari = rand() % 100;
	while (counterRoom != 1)
	{
		if (pari > 5)
		{
			counterRoom++;
		}
		else
		{

			posX = rand() % H_MAX;
			posY = rand() % W_MAX;

			if (map[posX][posY] == '*')
			{
				if (map[posX + 1][posY] == 'S' || map[posX][posY + 1] == 'S' || map[posX - 1][posY] == 'S' || map[posX][posY - 1] == 'S' ||
					map[posX + 1][posY] == 'M' || map[posX][posY + 1] == 'M' || map[posX - 1][posY] == 'M' || map[posX][posY - 1] == 'M' ||
					map[posX + 1][posY] == 'V' || map[posX][posY + 1] == 'V' || map[posX - 1][posY] == 'V' || map[posX][posY - 1] == 'V' ||
					map[posX + 1][posY] == 'C' || map[posX][posY + 1] == 'C' || map[posX - 1][posY] == 'C' || map[posX][posY - 1] == 'C')
				{
					map[posX][posY] = 'P';
					counterRoom++;
				}

			}
		}
	}
}

void MapGenerator::genEmiliRoom()
{
	int posX, posY;
	int emili;
	int counterRoom = 0;
	srand(time(NULL));
	emili = rand() % 100;

	while (counterRoom != 1)
	{
		if (emili > 1)
		{
			counterRoom++;
		}
		else
		{

			posX = rand() % H_MAX;
			posY = rand() % W_MAX;

			if (map[posX][posY] == '*')
			{
				if (map[posX + 1][posY] == 'S' || map[posX][posY + 1] == 'S' || map[posX - 1][posY] == 'S' || map[posX][posY - 1] == 'S' ||
					map[posX + 1][posY] == 'M' || map[posX][posY + 1] == 'M' || map[posX - 1][posY] == 'M' || map[posX][posY - 1] == 'M' ||
					map[posX + 1][posY] == 'V' || map[posX][posY + 1] == 'V' || map[posX - 1][posY] == 'V' || map[posX][posY - 1] == 'V' ||
					map[posX + 1][posY] == 'P' || map[posX][posY + 1] == 'P' || map[posX - 1][posY] == 'P' || map[posX][posY - 1] == 'P' ||
					map[posX + 1][posY] == 'C' || map[posX][posY + 1] == 'C' || map[posX - 1][posY] == 'C' || map[posX][posY - 1] == 'C')
				{
					map[posX][posY] = 'E';
					counterRoom++;
				}

			}
		}
	}
}

void MapGenerator::genMiniBossRoom()
{
	int posX, posY;
	int miniBoss;
	int counterRoom = 0;
	srand(time(NULL));
	miniBoss = rand() % 100;

	while (counterRoom != 1)
	{
		if (miniBoss > 5)
		{
			counterRoom++;
		}
		else
		{

			posX = rand() % H_MAX;
			posY = rand() % W_MAX;

			if (map[posX][posY] == '*')
			{
				if (map[posX + 1][posY] == 'S' || map[posX][posY + 1] == 'S' || map[posX - 1][posY] == 'S' || map[posX][posY - 1] == 'S' ||
					map[posX + 1][posY] == 'M' || map[posX][posY + 1] == 'M' || map[posX - 1][posY] == 'M' || map[posX][posY - 1] == 'M' ||
					map[posX + 1][posY] == 'V' || map[posX][posY + 1] == 'V' || map[posX - 1][posY] == 'V' || map[posX][posY - 1] == 'V' ||
					map[posX + 1][posY] == 'P' || map[posX][posY + 1] == 'P' || map[posX - 1][posY] == 'P' || map[posX][posY - 1] == 'P' ||
					map[posX + 1][posY] == 'E' || map[posX][posY + 1] == 'E' || map[posX - 1][posY] == 'E' || map[posX][posY - 1] == 'E' ||
					map[posX + 1][posY] == 'C' || map[posX][posY + 1] == 'C' || map[posX - 1][posY] == 'C' || map[posX][posY - 1] == 'C')
				{
					map[posX][posY] = 'b';
					counterRoom++;
				}

			}
		}
	}
}

void MapGenerator::genDefiRoom()
{
	int posX, posY;
	int defi;
	int counterRoom = 0;
	srand(time(NULL));
	defi = rand() % 100;

	while (counterRoom != 1)
	{
		if (defi > 5)
		{
			counterRoom++;
		}
		else
		{

			posX = rand() % H_MAX;
			posY = rand() % W_MAX;

			if (map[posX][posY] == '*')
			{
				if (map[posX + 1][posY] == 'S' || map[posX][posY + 1] == 'S' || map[posX - 1][posY] == 'S' || map[posX][posY - 1] == 'S' ||
					map[posX + 1][posY] == 'M' || map[posX][posY + 1] == 'M' || map[posX - 1][posY] == 'M' || map[posX][posY - 1] == 'M' ||
					map[posX + 1][posY] == 'V' || map[posX][posY + 1] == 'V' || map[posX - 1][posY] == 'V' || map[posX][posY - 1] == 'V' ||
					map[posX + 1][posY] == 'P' || map[posX][posY + 1] == 'P' || map[posX - 1][posY] == 'P' || map[posX][posY - 1] == 'P' ||
					map[posX + 1][posY] == 'E' || map[posX][posY + 1] == 'E' || map[posX - 1][posY] == 'E' || map[posX][posY - 1] == 'E' ||
					map[posX + 1][posY] == 'b' || map[posX][posY + 1] == 'b' || map[posX - 1][posY] == 'b' || map[posX][posY - 1] == 'b' ||
					map[posX + 1][posY] == 'C' || map[posX][posY + 1] == 'C' || map[posX - 1][posY] == 'C' || map[posX][posY - 1] == 'C')
				{
					map[posX][posY] = 'D';
					counterRoom++;
				}

			}
		}
	}

}

void MapGenerator::genEnigmeRoom()
{
	int posX, posY;
	int enigme;
	int counterRoom = 0;
	srand(time(NULL));
	enigme = rand() % 100;

	while (counterRoom != 1)
	{
		if (enigme > 10)
		{
			counterRoom++;
		}
		else
		{

			posX = rand() % H_MAX;
			posY = rand() % W_MAX;

			if (map[posX][posY] == '*')
			{
				if (map[posX + 1][posY] == 'S' || map[posX][posY + 1] == 'S' || map[posX - 1][posY] == 'S' || map[posX][posY - 1] == 'S' ||
					map[posX + 1][posY] == 'M' || map[posX][posY + 1] == 'M' || map[posX - 1][posY] == 'M' || map[posX][posY - 1] == 'M' ||
					map[posX + 1][posY] == 'V' || map[posX][posY + 1] == 'V' || map[posX - 1][posY] == 'V' || map[posX][posY - 1] == 'V' ||
					map[posX + 1][posY] == 'P' || map[posX][posY + 1] == 'P' || map[posX - 1][posY] == 'P' || map[posX][posY - 1] == 'P' ||
					map[posX + 1][posY] == 'E' || map[posX][posY + 1] == 'E' || map[posX - 1][posY] == 'E' || map[posX][posY - 1] == 'E' ||
					map[posX + 1][posY] == 'b' || map[posX][posY + 1] == 'b' || map[posX - 1][posY] == 'b' || map[posX][posY - 1] == 'b' ||
					map[posX + 1][posY] == 'D' || map[posX][posY + 1] == 'D' || map[posX - 1][posY] == 'D' || map[posX][posY - 1] == 'D' ||
					map[posX + 1][posY] == 'C' || map[posX][posY + 1] == 'C' || map[posX - 1][posY] == 'C' || map[posX][posY - 1] == 'C')
				{
					map[posX][posY] = 'e';
					counterRoom++;
				}

			}
		}
	}
}

void MapGenerator::genSacrificeRoom()
{
	int posX, posY;
	int sacrifice;
	int counterRoom = 0;
	srand(time(NULL));
	sacrifice = rand() % 100;

	while (counterRoom != 1)
	{
		if (sacrifice > 3)
		{
			counterRoom++;
		}
		else
		{

			posX = rand() % H_MAX;
			posY = rand() % W_MAX;

			if (map[posX][posY] == '*')
			{
				if (map[posX + 1][posY] == 'S' || map[posX][posY + 1] == 'S' || map[posX - 1][posY] == 'S' || map[posX][posY - 1] == 'S' ||
					map[posX + 1][posY] == 'M' || map[posX][posY + 1] == 'M' || map[posX - 1][posY] == 'M' || map[posX][posY - 1] == 'M' ||
					map[posX + 1][posY] == 'V' || map[posX][posY + 1] == 'V' || map[posX - 1][posY] == 'V' || map[posX][posY - 1] == 'V' ||
					map[posX + 1][posY] == 'P' || map[posX][posY + 1] == 'P' || map[posX - 1][posY] == 'P' || map[posX][posY - 1] == 'P' ||
					map[posX + 1][posY] == 'E' || map[posX][posY + 1] == 'E' || map[posX - 1][posY] == 'E' || map[posX][posY - 1] == 'E' ||
					map[posX + 1][posY] == 'b' || map[posX][posY + 1] == 'b' || map[posX - 1][posY] == 'b' || map[posX][posY - 1] == 'b' ||
					map[posX + 1][posY] == 'D' || map[posX][posY + 1] == 'D' || map[posX - 1][posY] == 'D' || map[posX][posY - 1] == 'D' ||
					map[posX + 1][posY] == 'e' || map[posX][posY + 1] == 'e' || map[posX - 1][posY] == 'e' || map[posX][posY - 1] == 'e' ||
					map[posX + 1][posY] == 'C' || map[posX][posY + 1] == 'C' || map[posX - 1][posY] == 'C' || map[posX][posY - 1] == 'C')
				{
					map[posX][posY] = 's';
					counterRoom++;
				}

			}
		}
	}
}



void MapGenerator::genMap()
{
	mapInit();
	genFirstRoom();
	genStandarRoom();
	genBossRoom();
	genChestAndMarchandRoom();
	genHealthRoom();
	genPariRoom();
	genEmiliRoom();
	genMiniBossRoom();
	genDefiRoom();
	genEnigmeRoom();
	genSacrificeRoom();
	drawMap();
}
