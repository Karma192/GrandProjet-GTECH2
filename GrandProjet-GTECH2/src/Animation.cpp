#include "Animation.h"

void Animation::InitAnimation(sf::String texturePath, sf::Sprite* sprite, float scale, int frameWidth, int frameHeight)
{
	aTexturePath = texturePath;
	aSprite = sprite;
	aFrameWidth = frameWidth;
	aFrameHeight = frameHeight;
	aScale = scale;

	texture.loadFromFile(aTexturePath);
	aSprite->setTexture(texture);

	frameRect = sf::IntRect(0, 0, aFrameWidth, aFrameHeight);
	aSprite->setTextureRect(frameRect);
	sf::Vector2f center(aSprite->getLocalBounds().width / 2.f, aSprite->getLocalBounds().height / 2.f);
	aSprite->setOrigin(center);
}

void Animation::Animate(int nbFramesAnim, int nbTotalFramesX, int startFrameLine, int startFrameColumn, float animationSpeed, bool doFlip)
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
		// If the rect is at the right border of the spritesheet, and it isn't the end of the animation, 
		// we put the rect on the next line on the first frame on the left
		if (frameRect.left >= (nbTotalFramesX - 1) * aFrameWidth && counter < nbFramesAnim)
		{
			frameRect.left =  0;
			frameRect.top += aFrameHeight;
			counter += 1;
		}
		// If the rect comes at the last frame of the animation, it goes back to the starting frame and reset the counter
		else if (counter >= nbFramesAnim)
		{
			frameRect.left = (startFrameColumn - 1) * aFrameWidth;
			frameRect.top = (startFrameLine - 1) * aFrameHeight;
			counter = 1;
		}
		// start
		else if (counter == 0)
		{
			frameRect.left = (startFrameColumn - 1) * aFrameWidth;
			frameRect.top = (startFrameLine - 1) * aFrameHeight;
			counter += 1;
		}
		else
		{
			frameRect.left += aFrameWidth;
			counter += 1;
		}
		aSprite->setTextureRect(frameRect);
		animationClock.restart();
	}
}