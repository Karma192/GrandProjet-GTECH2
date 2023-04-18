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
	GameMaster::GetInstance()->SetActiveMap(4);
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
	for (int i = 0; i < _spritevect.size(); i++) {
		GameMaster::GetGameData().window->draw(_spritevect[i]);
	}
}

void ToNextScene::CreateDoors(sf::Sprite spr, int posx, int posy) {
	spr.setPosition(posx, posy);
	_spritevect.push_back(spr);
}

bool ToNextScene::collidesWith(CollisionObject* other)
{
	if (Player* player = dynamic_cast<Player*>(other)) {
		for (int i = 0; i < _spritevect.size(); i++) {
			if (_spritevect[i].getGlobalBounds().intersects(player->cube.getGlobalBounds())) {
				map = i;
				ChangeMap();
				return true;
			}
		}
		if (_sprite.getGlobalBounds().intersects(player->cube.getGlobalBounds())) {
			GoToScene();
			return true;
		}
	}
	return false;
}

void ToNextScene::handleCollision(CollisionObject* other)
{
	if (dynamic_cast<Player*>(other)) {
		std::cout << "Collide with a door" << std::endl;
	}
}

void ToNextScene::GoToScene()
{
	GameMaster::GetInstance()->SetActiveScene(scene);
}

void ToNextScene::ChangeMap()
{
	std::cout << "map : " << map << std::endl;
	GameMaster::GetInstance()->SetActiveMap(map);
}