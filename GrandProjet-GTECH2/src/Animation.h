#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	sf::Sprite SpriteAnimation(int nbFramesAnim, int nbFramesX, int startFrameColumn, int startFrameLine, int endFrameColumn, int endFrameLine, int xImage, int yImage, sf::String texturePath, sf::Sprite sprite, sf::Vector2f moveSpeed);
	void AnimationInit(int xImage, int yImage, sf::String texturePath, sf::Sprite sprite);


private:
	sf::Clock clock;
	sf::Texture texture;
	int counter = 0;
	int flip = 1;
};

