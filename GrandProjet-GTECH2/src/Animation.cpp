#include "Animation.h"

void Animation::InitAnimation(sf::String texturePath, sf::Sprite* sprite, int frameWidth, int frameHeight, int totalFrames, int currentFrame)
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

	// Start to 0
	// exemple : 4 frames -> 0 - 3
	aCurrentFrame = currentFrame;

	aSprite->setScale(sf::Vector2f(3.0f, 3.0f));
	aSprite->setTexture(texture);

	frameRect = sf::IntRect(0, 0, aFrameWidth, aFrameHeight);

	aSprite->setTextureRect(frameRect);
}

void Animation::Animate(float animationSpeed)
{
	if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
		aCurrentFrame = (aCurrentFrame + 1) % aTotalFrames;
		frameRect.left = aCurrentFrame * aFrameWidth;
		aSprite->setTextureRect(frameRect);
		animationClock.restart();
	}
}