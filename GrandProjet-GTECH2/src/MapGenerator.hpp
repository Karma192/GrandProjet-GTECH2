
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <vector>
#include <string>

class MapGenerator {
public:
	int H_MAX = 10;
	int W_MAX = 10;
	int NB_ROOMS = 4;
	int firstRoomX = 0;
	int firstRoomY = 0; 

	std::string x;
	int place = 2;
	char map[10][10];

	
	MapGenerator();
	~MapGenerator();

	void attributePlace();
	void lastRoom();
	void maps();
	void resetAll();
	void mapInit();
	void drawMap();
	void genMap();
	void genFirstRoom();
	void genStandarRoom();
	void genChestAndMarchandRoom();
	void genHealthRoom();
	void genBossRoom();
	void genPariRoom();
	void genEmiliRoom();
	void genMiniBossRoom();
	void genDefiRoom();
	void genEnigmeRoom();
	void genSacrificeRoom();


private:

};


