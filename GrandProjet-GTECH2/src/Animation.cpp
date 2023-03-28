#include "Animation.h"

void Animation::InitAnimation(sf::String texturePath, sf::Sprite* sprite, int frameWidth, int frameHeight, int totalFrames, int currentFrame, float scale)
{
	aTexturePath = texturePath;
	texture.loadFromFile(aTexturePath);

	aSprite = sprite;
	aFrameWidth = frameWidth;
	aFrameHeight = frameHeight;
	aTotalFrames = totalFrames;
	aScale = scale;
	aCurrentFrame = currentFrame;
	// Current frame start to 0
	// exemple : 4 frames -> 0 - 3

	aSprite->setTexture(texture);

	frameRect = sf::IntRect(0, 0, aFrameWidth, aFrameHeight);

	aSprite->setTextureRect(frameRect);
}

void Animation::Animate(float animationSpeed, bool doFlip)
{
	if (doFlip)
	{
		aSprite->setScale(-aScale, aScale);
	}
	else
	{
		aSprite->setScale(aScale, aScale);
	}

	if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
		aCurrentFrame = (aCurrentFrame + 1) % aTotalFrames;
		frameRect.left = aCurrentFrame * aFrameWidth;
		aSprite->setTextureRect(frameRect);
		animationClock.restart();
	}
}