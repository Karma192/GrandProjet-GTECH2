#include "Animation.h"

void Animation::LoadAnimation(std::string filename, sf::Sprite *sprite, int frameWidth, int frameHeight, float scaleRatio)
{
    isAnimating = false;
    _scaleRatio = scaleRatio;
    _sprite = sprite;
    stateAnimation = 1;

    if (!texture.loadFromFile(filename))
    {
        std::cout << "Erreur chargement spritesheet" << std::endl;
        return;
    }

    int numColumns = texture.getSize().x / frameWidth;
    int numRows = texture.getSize().y / frameHeight;

    for (int y = 0; y < numRows; y++) {
        for (int x = 0; x < numColumns; x++) {
            sf::IntRect rect(x * frameWidth, y * frameHeight, frameWidth, frameHeight);
            frames.push_back(rect);
        }
    }

    _sprite->setOrigin(frameWidth/2, frameHeight/2);
    _sprite->setTexture(texture);
}

void Animation::SetAnimation()
{

}

void Animation::Animate(std::vector<int> frameIndex, float animSpeed, bool repeat, bool flip, int firstFrame)
{
    if (flip)
    {
        // to the right
        _sprite->setScale(-_scaleRatio, _scaleRatio);
    }
    else
    {
        // to the left
        _sprite->setScale(_scaleRatio, _scaleRatio);
    }

    if (clock.getElapsedTime().asSeconds() >= animSpeed && repeat && !isAnimating)
    {
        currentFrame = (currentFrame + 1) % frameIndex.size();
        _sprite->setTextureRect(frames[frameIndex[currentFrame]]);
        clock.restart();
    }

    /*if (!repeat && !isAnimating)
    {
        for (currentFrame = 0; currentFrame < frameIndex.size(); currentFrame++)
        {
            sf::Clock clockTest;

            if (clockTest.getElapsedTime().asSeconds() >= animSpeed)
            {
                _sprite->setTextureRect(frames[frameIndex[currentFrame]]);
                clockTest.restart();
            }
        }
    }*/
}