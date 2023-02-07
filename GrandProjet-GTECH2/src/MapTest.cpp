#include "MapTest.hpp"

Map::Map()
{
    village.load("C:/Users/agrandpaul/Documents/GitHub/GrandProjet-GTECH2/GrandProjet-GTECH2/ressources/map/village/village.tmx");
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