#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	void AnimationInit(sf::String texturePath, sf::Sprite* sprite, int startFrameColumn, int xImage, int yImage);
	void SpriteAnimation(int nbFramesAnim, int nbTotalFramesX, int startFrameLine, int endFrameColumn, int endFrameLine);

	void InitAnimation(sf::String texturePath, sf::Sprite* sprite, int frameWidth, int frameHeight);
	void Animate(int totalFrames, float animationSpeed, int currentFrame);

private:
	sf::Clock clock;
	sf::Texture texture;
	int counter = 2;
	int flip = 1;

	int aStartFrameColumn;
	int aXImage;
	int aYImage;
	sf::Sprite* aSprite;
	sf::String aTexturePath;
	sf::IntRect aRectSourceSprite;

	// TEST
	sf::Clock animationClock;
	sf::IntRect frameRect;

	int aFrameWidth;
	int aFrameHeight;
};

