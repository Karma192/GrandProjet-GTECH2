#pragma once
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

class ContactManager {
public:
	ContactManager();
	virtual ~ContactManager();

	void Collide(sf::RectangleShape* rect, sf::RectangleShape* rect2);
	bool IsDamaged(sf::FloatRect rect, sf::FloatRect rect2);

	bool damaged;

private:

};