#include "Animation.h"

sf::Sprite Animation::SpriteAnimation(int nbFramesAnim, int nbTotalFramesX, int startFrameColumn, int startFrameLine, int endFrameColumn, int endFrameLine, int xImage, int yImage, sf::String texturePath, sf::Sprite sprite, sf::Vector2f moveSpeed)
{
	sf::IntRect rectSourceSprite(counter * xImage, 0, xImage, yImage);
	texture.loadFromFile(texturePath);
	sprite.setTexture(texture);
	sprite.setTextureRect(rectSourceSprite);

	if (moveSpeed.x > 0.01f) 
	{
		flip = false;
	}
	else if (moveSpeed.x < -0.01f) 
	{
		flip = true;
	}

	sprite.scale(flip * 3.0f, 3.0f);
	if (clock.getElapsedTime().asMilliseconds() >= 100) {
		// If the rect is at the right border of the spritesheet, and it isn't the end of the animation, we put the rect on the next line on the first frame on the left
		if (rectSourceSprite.left >= (nbTotalFramesX - 1) * xImage + ((startFrameColumn-1) * xImage) && counter < nbFramesAnim-1)
		{
			rectSourceSprite.left = 0;
			rectSourceSprite.top += yImage;
			counter += 1;
		}
		// If the rect comes at the last frame of the animation, it goes back to the starting frame and reset the counter
		else if (counter >= nbFramesAnim-1)
		{
			rectSourceSprite.left = (startFrameColumn-1) * xImage;
			rectSourceSprite.top = (startFrameLine-1) * yImage;
			counter = 0;
		}
		// The rect goes to the next frame on the right
		else 
		{
			rectSourceSprite.left += xImage;
			counter += 1;
		}
		sprite.setTextureRect(rectSourceSprite);
		clock.restart();
	}
	
	return sprite;
}

void Animation::AnimationInit(int xImage, int yImage, sf::String texturePath, sf::Sprite sprite)
{
}

