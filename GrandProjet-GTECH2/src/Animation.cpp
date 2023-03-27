#include "Animation.h"

void Animation::AnimationInit(sf::String texturePath, sf::Sprite* sprite, int startFrameColumn, int xImage, int yImage)
{
	aTexturePath = texturePath;
	aSprite = sprite;
	aStartFrameColumn = startFrameColumn;
	aXImage = xImage;
	aYImage = yImage;

	texture.loadFromFile(aTexturePath);
	aSprite->setTexture(texture);
	aSprite->scale(3.0f, 3.0f);
	aRectSourceSprite = sf::IntRect(aStartFrameColumn * aXImage, 0, aXImage, aYImage);
}

void Animation::SpriteAnimation(int nbFramesAnim, int nbTotalFramesX, int startFrameLine, int endFrameColumn, int endFrameLine)
{
	if (clock.getElapsedTime().asMilliseconds() >= 500) {
		// If the rect is at the right border of the spritesheet, and it isn't the end of the animation, 
		// we put the rect on the next line on the first frame on the left
		if (aRectSourceSprite.left >= (nbTotalFramesX - 1) * aXImage && counter < nbFramesAnim)
		{
			std::cout << "next line" << std::endl;
			aRectSourceSprite.left = 0;
			aRectSourceSprite.top += aYImage;
			counter += 1;
		}
		// If the rect comes at the last frame of the animation, it goes back to the starting frame and reset the counter
		else if (counter >= nbFramesAnim)
		{
			std::cout << "starting frame" << std::endl;
			aRectSourceSprite.left = (aStartFrameColumn-1) * aXImage;
			aRectSourceSprite.top = (startFrameLine-1) * aYImage;
			counter = 1;
		}
		// The rect goes to the next frame on the right
		else 
		{
			std::cout << "next frame" << std::endl;
			aRectSourceSprite.left += aXImage;
			counter += 1;
		}
		aSprite->setTextureRect(aRectSourceSprite);
		clock.restart();
	}
}

void Animation::InitAnimation(sf::String texturePath, sf::Sprite* sprite, int frameWidth, int frameHeight)
{
	aSprite = sprite;
	aTexturePath = texturePath;

	texture.loadFromFile(aTexturePath);
	aSprite->setTexture(texture);
	aSprite->scale(3.0f, 3.0f);

	aFrameWidth = frameWidth;
	aFrameHeight = frameHeight;

	frameRect = sf::IntRect(0, 0, aFrameWidth, aFrameHeight);
	aSprite->setTextureRect(frameRect);
}

void Animation::Animate(int totalFrames, float animationSpeed,int currentFrame)
{
	if (animationClock.getElapsedTime().asSeconds() >= animationSpeed)
	{
		//DEBUG
		std::cout << "curent frame" + currentFrame << std::endl;

		currentFrame = (currentFrame + 1) % totalFrames;
		frameRect.left = currentFrame * aFrameWidth;
		aSprite->setTextureRect(frameRect);
		animationClock.restart();
	}
}