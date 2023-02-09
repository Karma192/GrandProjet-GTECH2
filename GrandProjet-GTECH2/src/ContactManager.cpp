#include "ContactManager.hpp"

ContactManager::ContactManager()
{
}

ContactManager::~ContactManager()
{
}

void ContactManager::Collide(sf::RectangleShape* rect, sf::RectangleShape* rect2)
{
	sf::FloatRect rect1 = rect->getGlobalBounds();
	sf::FloatRect rect3 = rect2->getGlobalBounds();

	if (rect1.intersects(rect3)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            rect->move(sf::Vector2f(0.f, 5));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            rect->move(sf::Vector2f(0.f, -5));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            rect->move(sf::Vector2f(5, 0.f));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            rect->move(sf::Vector2f(-5, 0.f));
        }
	}
}

bool ContactManager::IsDamaged(sf::FloatRect rect, sf::FloatRect rect2)
{
	if (rect.intersects(rect2)) {
		std::cout << "Damage";
		return true;
	}
	return false;
}