#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <vector>
#include <string>
#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include "SFMLLayer.hpp"
#include "GameObject/Player/Player.hpp"
#include "GameObject/GameObject.hpp"

#define TILE_SIZE 16

class CollideTile : public GameObject
{
public:
    CollideTile();
    CollideTile(sf::Vector2f position);
    virtual ~CollideTile();

    virtual void Loop()override;
    virtual void Render()override;

    virtual void OnCollisionEnter(PhysicBody* other)override;

private:
    sf::Vector2f GetMTV(PhysicBody*);
};

class Room : public GameObject
{
public:

    Room() = default;
    Room(std::string, sf::Vector2f);
    virtual ~Room();

    virtual void Loop()override;
    virtual void Render()override;

    virtual void OnCollisionEnter(PhysicBody* other)override;

    // Fonction pour set les tiles de collision
    void GetTilesBounds();
    // Fonction pour récupérer les tiles de collision
    std::vector<CollideTile*> GetCollideTiles();

    MapLayer* background;
    MapLayer* decoration;
    MapLayer* collision;

    std::vector<sf::RectangleShape> rect;
    sf::RectangleShape rectCube;

private:
    std::vector<CollideTile*> _collideTiles;
    sf::Vector2f _size;
    std::string path = "ressources/map/";
    tmx::Map map;
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
    RoomWallet* wallet;


    MapGenerator();
    virtual ~MapGenerator();

    virtual void Init()override;

    virtual void Loop()override;
    virtual void Render()override;

    virtual void OnCollisionEnter(PhysicBody* other)override;

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
