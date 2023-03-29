#include "ToNextScene.hpp"
#include "GameMaster.hpp"

ToNextScene::ToNextScene()
{
}

ToNextScene::ToNextScene(int s, sf::Sprite spr, int posx, int posy)
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
