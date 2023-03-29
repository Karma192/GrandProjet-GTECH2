#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	void InitAnimation(sf::String texturePath, sf::Sprite* sprite, float scale, int frameWidth, int frameHeight);
	void Animate(int nbFramesAnim, int nbTotalFramesX, int startFrameLine, int startFrameColumn, float animationSpeed, bool doFlip);

private:
	sf::Clock animationClock;
	sf::Texture texture;
	sf::Sprite* aSprite;
	sf::String aTexturePath;
	sf::IntRect frameRect;

	int aFrameWidth;
	int aFrameHeight;
	int aTotalFrames;
	int aCurrentFrame;
	int aColumns;
	int aRows;
	int counter;
	int aStartFrame;
	int aEndFrame;
	int aNumColumns;
	int aNumRows;

	float aScale;
};

