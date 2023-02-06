#include "Animation.h"

void Animation::SpriteAnimation(int xImage, int yImage, int nbFrames, sf::RenderWindow* window, sf::String texturePath, sf::Sprite sprite)
{
	texture.loadFromFile(texturePath);
	sf::IntRect rectSourceSprite(0, 0, xImage, yImage);
	sprite.setTexture(texture);
	sprite.setTextureRect(rectSourceSprite);
	sprite.scale(3.0f, 3.0f);

	if (clock.getElapsedTime().asMilliseconds() >= 500) {
		if (rectSourceSprite.left == (nbFrames - 1) * xImage)
			rectSourceSprite.left = 0;
		else
			rectSourceSprite.left += xImage;

		sprite.setTextureRect(rectSourceSprite);
		clock.restart();
	}
	window->draw(sprite);
}