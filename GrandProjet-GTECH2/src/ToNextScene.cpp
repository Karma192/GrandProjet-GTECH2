#include "ToNextScene.hpp"

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

bool ToNextScene::collidesWith(CollisionObject* other)
{
	if (Player* player = dynamic_cast<Player*>(other)) {
		if (_sprite.getGlobalBounds().intersects(player->cube.getGlobalBounds())) {
			return true;
		}
	}
	return false;
}

void ToNextScene::handleCollision(CollisionObject* other)
{
	if (dynamic_cast<Player*>(other)) {
		GoToScene();
		std::cout << "Collide with a door" << std::endl;
	}
}

void ToNextScene::GoToScene()
{
	GameMaster::GetInstance()->SetActiveScene(scene);
}
