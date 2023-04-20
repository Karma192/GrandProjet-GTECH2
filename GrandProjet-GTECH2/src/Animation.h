#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:
	void LoadAnimation(std::string filename, sf::Sprite *sprite, int frameWidth, int frameHeight, float scaleRatio);
	void SetAnimation();
	void Animate(std::vector<int> frameIndex, float animSpeed, bool repeat, bool flip, int firstFrame);

	sf::Clock clock;
	sf::Clock cooldownAnimation;
	sf::Texture texture;
	sf::Sprite* _sprite;

	std::vector<sf::IntRect> frames;
	std::vector<int> frameIndexGlobal;

	float _scaleRatio;
	int currentFrame;
	bool isAnimating;
	bool isAnimationEnd;
	int stateAnimation;

private:

};

