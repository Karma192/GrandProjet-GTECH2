#include "ToNextScene.hpp"
#include "../Instance/GameMaster.hpp"

ToNextScene::ToNextScene() : GameObject(this)
{
}

ToNextScene::ToNextScene(int s, sf::Sprite spr, int posx, int posy) : GameObject(this)
{
	scene = s;
	_sprite = spr;
	_sprite.setPosition(posx, posy);
}

ToNextScene::~ToNextScene()
{
}

void ToNextScene::Loop()
{
}

void ToNextScene::Render()
{
	GameMaster::GetGameData().window->draw(_sprite);
}

void ToNextScene::GoToScene()
{
	GameMaster::GetInstance()->SetActiveScene(scene);
}
