#include "../Scene/Scene.hpp"
#include "Game.hpp"

Game* game = new Game;

int main()
{
    game->GameLoop();
}