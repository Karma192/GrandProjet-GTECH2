#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	void SpriteAnimation(int xImage, int yImage, int nbFrames, sf::RenderWindow* window, sf::String texturePath, sf::Sprite sprite);

private:
	sf::Clock clock;
	sf::Event event;
	sf::Texture texture;
};

