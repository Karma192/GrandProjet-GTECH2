#include "Animation.h"

void Animation::InitAnimation(sf::String texturePath, sf::Sprite* sprite, int frameWidth, int frameHeight, int totalFrames, int animationSpeed, int currentFrame)
{
	aTexturePath = texturePath;

	if (!texture.loadFromFile(aTexturePath))
	{
		std::cout << "error load tileset" << std::endl;
	}

	aSprite = sprite;
	aFrameWidth = frameWidth;
	aFrameHeight = frameHeight;
	aTotalFrames = totalFrames;
	aAnimationSpeed = animationSpeed;
	aCurrentFrame = currentFrame;

	aSprite->setPosition(sf::Vector2f(200, 200));
	aSprite->setScale(sf::Vector2f(3.0f, 3.0f));
	aSprite->setTexture(texture);

	frameRect = sf::IntRect(0, 0, aFrameWidth, aFrameHeight);

	// Calculate the rectangle for the third frame
	frameRect.left = aFrameWidth * 0;

	aSprite->setTextureRect(frameRect);
}

void Animation::Animate()
{
	if (animationClock.getElapsedTime().asMilliseconds() >= aAnimationSpeed) {
		aCurrentFrame = (aCurrentFrame + 1) % aTotalFrames;
		frameRect.left = aCurrentFrame * aFrameWidth;
		aSprite->setTextureRect(frameRect);
		animationClock.restart();
	}
}