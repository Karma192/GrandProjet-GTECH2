#include "Animation.h"

void Animation::SpriteAnimation(int xImage, int yImage, int nbFrames, sf::RenderWindow* window, sf::String texturePath, sf::Sprite sprite)
{
	sf::IntRect rectSourceSprite(compteur * xImage, 0, xImage, yImage);
	texture.loadFromFile(texturePath);
	sprite.setTexture(texture);
	sprite.setTextureRect(rectSourceSprite);
	sprite.scale(3.0f, 3.0f);

	if (clock.getElapsedTime().asMilliseconds() >= 100) {
		if (rectSourceSprite.left >= (nbFrames - 1) * xImage) 
		{
			rectSourceSprite.left = 0;
			compteur = 0;
		}
		else 
		{
			rectSourceSprite.left += xImage;
			compteur += 1;
		}
		sprite.setTextureRect(rectSourceSprite);
		clock.restart();
	}
	window->draw(sprite);
}