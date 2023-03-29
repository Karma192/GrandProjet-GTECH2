#include "Object.hpp"

Object::Object()
{
	randomX = rand();
	randomY = rand();
	randomPosObject.setSize(sf::Vector2f(5, 5));
	randomPosObject.setFillColor(sf::Color::Green);
	randomPosObject.setPosition(randomX % 1920 - 5, randomY % 1080 -5);

	randomX = rand();
	randomY = rand();
	randomPosObject2.setSize(sf::Vector2f(5, 5));
	randomPosObject2.setFillColor(sf::Color::Magenta);
	randomPosObject2.setPosition(randomX % 1920 - 5, randomY % 1080 - 5);
}

Object::~Object()
{
}

void Object::Loop()
{

}

void Object::Render()
{
	gameData = GameMaster::GetInstance()->GetGameData();
	if (!StopDraw) {
		gameData.window->draw(randomPosObject);
		gameData.window->draw(randomPosObject2);
	}
}

bool Object::collidesWith(CollisionObject* other)
{
	if (Player* player = dynamic_cast<Player*>(other)) {
		if (randomPosObject.getGlobalBounds().intersects(player->playerSprite.getGlobalBounds())) {
			return true;
		}
	}
}

void Object::handleCollision(CollisionObject* other)
{
	if (dynamic_cast<Player*>(other)) {
		StopDraw = true;
	}
}
