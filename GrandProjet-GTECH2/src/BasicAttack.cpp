#include "BasicAttack.hpp"

BasicAttack::BasicAttack() {

}

BasicAttack::BasicAttack(sf::RectangleShape* cube) 
{
    
}

BasicAttack::~BasicAttack()
{
}

void BasicAttack::Loop()
{
	if (lifeTime <= 0) 
	{
		Destroy();
	}
	else {
		lifeTime--;
	}
}

void BasicAttack::Render()
{
    gameData.window->draw(hitboxTest);
}

bool BasicAttack::collidesWith(CollisionObject* other)
{
    if (Enemies* enemy = dynamic_cast<Enemies*>(other)) {
        if (hitboxTest.getGlobalBounds().intersects(enemy->cube2.getGlobalBounds())) {
            return true;
        }
    }
    if (Player* player = dynamic_cast<Player*>(other)) {
        playerCube = player->cube;
        if (hitboxTest.getGlobalBounds().intersects(player->cube.getGlobalBounds())) {
            return true;
        }
    }

    return false;
}

void BasicAttack::handleCollision(CollisionObject* other)
{
    if (dynamic_cast<Enemies*>(other)) {
        std::cout << "attack";
    }
    if (dynamic_cast<Player*>(other)) {

    }
}

void BasicAttack::Attack(int x, int y)
{
    hitboxTest.setSize(sf::Vector2f(30.f, 30.f));
    hitboxTest.setFillColor(sf::Color::Blue);
    hitboxTest.setPosition(playerCube.getPosition());

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        hitboxTest.setPosition(x ,y - 30.f);   
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        hitboxTest.setPosition(x, y + 30.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        hitboxTest.setPosition(x - 30.f, y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        hitboxTest.setPosition(x + 30.f, y);
    }
}
