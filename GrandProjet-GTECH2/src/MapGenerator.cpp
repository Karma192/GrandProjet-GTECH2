#include "MapGenerator.hpp"
#include "GameMaster.hpp"

// Room class

Room::Room(std::string file)
{
	map.load(path + file);
	background = new MapLayer(map, 0);
	decoration = new MapLayer(map, 1);
	collision = new MapLayer(map, 2);
	rect.clear();
	GetTilesBounds();
}

Room::~Room()
{

}

void Room::Loop()
{

}

void Room::Render()
{
	GameMaster::GetInstance()->GetGameData().window->draw(*background);
	GameMaster::GetInstance()->GetGameData().window->draw(*decoration);
	GameMaster::GetInstance()->GetGameData().window->draw(*collision);
	for (int i = 0; i < rect.size(); i++) {
		GameMaster::GetInstance()->GetGameData().window->draw(rect[i]);
	}
}

bool Room::collidesWith(CollisionObject* other)
{
	return false;
}

void Room::GetTilesBounds() {
	for (int x = 0; x < map.getTileCount().x; x++) {
		for (int y = 0; y < map.getTileCount().y; y++) {
			if(collision->getTile(x,y).ID != 0){
				i++;
				rectCube.setSize(sf::Vector2f(16, 16));
				rectCube.setFillColor(sf::Color::Red);
				rectCube.setPosition(sf::Vector2f(16*x,16*y));
				if (rectCube.getGlobalBounds().contains(playerCube)) {
					collisionCheck = true;
				}
				rect.push_back(rectCube);
			}
		}
	}
}

void Room::handleCollision(CollisionObject* other)
{

}

// RoomWallet class

RoomWallet::RoomWallet()
{
	LoadAll();
}

RoomWallet::~RoomWallet()
{

}

Room* RoomWallet::GetRoom(int room)
{
	return wallet[room];
} 

void RoomWallet::LoadAll()
{
	Room* inn = new Room("village/inside_tavern.tmx");
	wallet.push_back(inn);

	Room* spawn = new Room("dungeon/spawn_room.tmx");
	wallet.push_back(spawn);

	Room* boss = new Room("dungeon/boss_room.tmx");
	wallet.push_back(boss);

	Room* chest = new Room("dungeon/chest_room.tmx");
	wallet.push_back(chest);

	Room* trans = new Room("dungeon/transition_room.tmx");
	wallet.push_back(trans);
}

// MapGenerator class

MapGenerator::MapGenerator() {
	wallet = new RoomWallet();
	genMap();
	FirstRoomDetection();

	std::cout << "NORTH :" << map[_playerPosY - 1][_playerPosX] << std::endl;
	std::cout << "EAST :" << map[_playerPosY][_playerPosX + 1] << std::endl;
	std::cout << "SOUTH :" << map[_playerPosY + 1][_playerPosX] << std::endl;
	std::cout << "WEST :" << map[_playerPosY][_playerPosX - 1] << std::endl;

	_nextPlayerPosX = _playerPosX;
	_nextPlayerPosY = _playerPosY;
}

MapGenerator::~MapGenerator() {

}

void MapGenerator::Loop() {
	FirstRoomDetection();
}

void MapGenerator::Render() {
	switch (GameMaster::GetGameData().indexScene)
	{
	case LOBBY:
		switch (GameMaster::GetGameData().indexMap) {
		case NORTH:
			wallet->GetRoom(0)->Render();
			break;
		case EAST:
			wallet->GetRoom(1)->Render();
			break;
		case SOUTH:
			wallet->GetRoom(2)->Render();
			break;
		case WEST:
			wallet->GetRoom(3)->Render();
			break;
		default:
			wallet->GetRoom(0)->Render();
			break;
		}
		break;
	case INGAME:
		switch (GameMaster::GetGameData().indexMap) {
		case NORTH:
			if (map[_playerPosX - 1][_playerPosY] != '*') {
				/*if (_lastPos == '#') {
					_lastPos = 'F';
				}
				map[_playerPosX][_playerPosY] = _lastPos;*/

				_nextRoom = map[_playerPosX - 1][_playerPosY];

				_lastPos = _nextRoom;
				AdjacentRoomDetection();
				//map[_nextPlayerPosY - 1][_nextPlayerPosX] = '&';
			}
			break;
		case EAST:
			if (map[_playerPosX][_playerPosY + 1] != '*') {
				/*if (_lastPos == '#') {
					_lastPos = 'F';
				}
				map[_playerPosX][_playerPosY] = _lastPos;*/

				_nextRoom = map[_playerPosX][_playerPosY + 1];

				_lastPos = _nextRoom;
				AdjacentRoomDetection();
				//map[_nextPlayerPosY][_nextPlayerPosX + 1] = '&';

			}
			break;
		case SOUTH:
			if (map[_playerPosX + 1][_playerPosY] != '*') {
				/*if (_lastPos == '#') {
					_lastPos = 'F';
				}
				map[_playerPosX][_playerPosY] = _lastPos;*/

				_nextRoom = map[_playerPosX + 1][_playerPosY];

				_lastPos = _nextRoom;
				AdjacentRoomDetection();
				//map[_nextPlayerPosY + 1][_nextPlayerPosX] = '&';

			}
			break;
		case WEST:
			if (map[_playerPosX][_playerPosY - 1] != '*') {
				/*if (_lastPos == '#') {
					_lastPos = 'F';
				}
				map[_playerPosX][_playerPosY] = _lastPos;*/

				_nextRoom = map[_playerPosX][_playerPosY - 1];

				_lastPos = _nextRoom;
				AdjacentRoomDetection();
				//map[_nextPlayerPosY][_nextPlayerPosX - 1] = '&';
				
			}
			break;
		default:
			wallet->GetRoom(1)->Render();
			break;
		}
		break;
	default:
		wallet->GetRoom(1)->Render();
		break;
	}

	std::cout << "X : " << _playerPosX << std::endl;
	std::cout << "Y : " << _playerPosY << std::endl;
	drawMap();
}

void MapGenerator::AdjacentRoomDetection() {
	switch (_nextRoom) {
	case 'C':
		wallet->GetRoom(3)->Render();
		break;
	case 'M':
		break;
	case 'V':
		break;
	case 'S':
		wallet->GetRoom(4)->Render();
		break;
	case 'B':
		wallet->GetRoom(2)->Render();
		break;
	case 'P':
		break;
	case 'E':
		break;
	case 'b':
		break;
	case 'D':
		break;
	case 'e':
		break;
	case 's':
		break;
	default:
		break;
	}
	FirstRoomDetection();
}

void MapGenerator::FirstRoomDetection() {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 'F' || map[i][j] == '&') {
				_playerPosX = i;
				_playerPosY = j;
			}
		}
	}
}

bool MapGenerator::collidesWith(CollisionObject* other)
{
	if (Player* player = dynamic_cast<Player*>(other)) {
		for (int i = 0; i < wallet->GetRoom(0)->rect.size(); i++) {
			if (wallet->GetRoom(0)->rect[i].getGlobalBounds().intersects(player->cube.getGlobalBounds())) {
				return true;
			}
		}
	}
	return false;
}

void MapGenerator::handleCollision(CollisionObject* other)
{
	if (dynamic_cast<Player*>(other)) {
	}
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
	std::cout << std::endl;
}