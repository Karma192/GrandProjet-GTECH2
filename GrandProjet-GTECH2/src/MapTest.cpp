#include "MapTest.hpp"

Map::Map()
{
    village.load(path + "village/village.tmx");
    layerZero = new MapLayer(village, 0);
    layerOne = new MapLayer(village, 1);
    layerTwo = new MapLayer(village, 2);
}

Map::~Map()
{

}

void Map::Render()
{
    gameData = GetGameData();
    gameData.window->draw(*layerZero);
    gameData.window->draw(*layerOne);
    gameData.window->draw(*layerTwo);
}