#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	void AnimationInit(sf::String texturePath, sf::Sprite sprite, int startFrameColumn, int xImage, int yImage);
	sf::Sprite SpriteAnimation(int nbFramesAnim, int nbTotalFramesX,
		int startFrameLine, int endFrameColumn, int endFrameLine);
	void flipSprite(sf::Sprite sprite, sf::Vector2f moveSpeed);


private:
	sf::Clock clock;
	sf::Texture texture;
	int counter = 0;
	int flip = 1;

	int aStartFrameColumn;
	int aXImage;
	int aYImage;
	sf::Sprite aSprite;
	sf::String aTexturePath;
	sf::IntRect aRectSourceSprite;
};

