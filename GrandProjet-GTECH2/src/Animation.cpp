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
	sf::IntRect rectSourceSprite(aStartFrameColumn * aXImage, 0, aXImage, aYImage);
	aRectSourceSprite = rectSourceSprite;
}


void Animation::SpriteAnimation(int nbFramesAnim, int nbTotalFramesX, 
	int startFrameLine, int endFrameColumn, int endFrameLine)
{
	if (clock.getElapsedTime().asMilliseconds() >= 100) {
		// If the rect is at the right border of the spritesheet, and it isn't the end of the animation, 
		// we put the rect on the next line on the first frame on the left
		if (aRectSourceSprite.left >= (nbTotalFramesX - 1) * aXImage - ((aStartFrameColumn-1) * aXImage) && counter < nbFramesAnim)
		{
			aRectSourceSprite.left = 0;
			aRectSourceSprite.top += aYImage;
			counter += 1;
		}
		// If the rect comes at the last frame of the animation, it goes back to the starting frame and reset the counter
		else if (counter >= nbFramesAnim)
		{
			aRectSourceSprite.left = (aStartFrameColumn-1) * aXImage;
			aRectSourceSprite.top = (startFrameLine-1) * aYImage;
			counter = 1;
		}
		// The rect goes to the next frame on the right
		else 
		{
			aRectSourceSprite.left += aXImage;
			counter += 1;
		}
		aSprite->setTextureRect(aRectSourceSprite);
		clock.restart();
	}
	
}

void Animation::flipSprite(sf::Sprite sprite, sf::Vector2f moveSpeed)
{
	if (moveSpeed.x > 0.01f)
	{
		flip = 1;
	}
	else if (moveSpeed.x < -0.01f)
	{
		flip = -1;
	}

	sprite.scale(flip * 3.0f, 3.0f);
}


