#include "ContactManager.hpp"

ContactManager::ContactManager()
{
}

ContactManager::~ContactManager()
{
}

void ContactManager::Collide(sf::FloatRect rect, sf::FloatRect rect2)
{
	if (rect.intersects(rect2)) {
		std::cout << "test";
	}
}

