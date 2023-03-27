#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <vector>
#include <string>
#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include "SFMLLayer.hpp"
#include "Player.hpp"
#include "GameObject.hpp"

class Room : public GameObject
{
public:

    Room();
    Room(std::string);
    virtual ~Room();

    virtual void Loop()override;
    virtual void Render()override;

    bool collidesWith(CollisionObject* other) override;
    void handleCollision(CollisionObject* other) override;

    void GetTilesBounds();

    MapLayer* background;
    MapLayer* decoration;
    MapLayer* collision;

    std::vector<sf::RectangleShape> rect;
private:
    std::string path = "ressources/map/";
    tmx::Map map;
    sf::RectangleShape rectCube;
    sf::FloatRect playerCube;
    int i = 0;
    bool collisionCheck = false;
};

class RoomWallet
{
public:
    RoomWallet();
    virtual ~RoomWallet();

    Room* GetRoom(int);
private:
    void LoadAll();

    std::vector<Room*> wallet;
};

class MapGenerator : public GameObject
{
public:
    int H_MAX = 10;
    int W_MAX = 10;
    int NB_ROOMS = 4;
    int firstRoomX = 0;
    int firstRoomY = 0;

    std::string x;
    int place = 2;
    char map[10][10];
    RoomWallet wallet;


    MapGenerator();
    ~MapGenerator();

    virtual void Loop()override;
    virtual void Render()override;

    bool collidesWith(CollisionObject* other) override;
    void handleCollision(CollisionObject* other) override;

private:

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

};
