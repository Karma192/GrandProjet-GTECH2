#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:
	void LoadAnimation(std::string filename, sf::Sprite &sprite, int frameWidth, int frameHeight, float scaleRatio);
	void SetAnimation(bool doFlip, int firstFrame);
	void Animate(float animSpeed);

private:
	sf::Clock clock;
	sf::Texture texture;
	sf::Sprite _sprite;

	std::vector<sf::IntRect> frames;
	std::vector<int> frameIndex;
	
	float _scaleRatio;
	int currentFrame;
};

