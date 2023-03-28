#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	void InitAnimation(sf::String texturePath, sf::Sprite* sprite, int frameWidth, int frameHeight, int totalFrames, int animationSpeed, int currentFrame);
	void Animate();

	sf::Clock animationClock;
	sf::Texture texture;
	sf::Sprite* aSprite;
	sf::String aTexturePath;
	sf::IntRect frameRect;

	int aFrameWidth;
	int aFrameHeight;
	int aTotalFrames;
	int aAnimationSpeed;
	int aCurrentFrame;

private:

};

