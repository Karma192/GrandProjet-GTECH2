#include "Animation.h"

void Animation::LoadAnimation(std::string filename, sf::Sprite &sprite, int frameWidth, int frameHeight, float scaleRatio)
{
    if (!texture.loadFromFile(filename))
    {
        std::cout << "Erreur chargement spritesheet" << std::endl;
        return;
    }

    _sprite = sprite;
    _sprite.setTexture(texture);

    int numColumns = texture.getSize().x / frameWidth;
    int numRows = texture.getSize().y / frameHeight;

    for (int y = 0; y < numRows; y++) {
        for (int x = 0; x < numColumns; x++) {
            sf::IntRect rect(x * frameWidth, y * frameHeight, frameWidth, frameHeight);
            frames.push_back(rect);
        }
    }
}

void Animation::SetAnimation(bool doFlip, int firstFrame)
{
    if (doFlip)
    {
        _sprite.setScale(-_scaleRatio, _scaleRatio);
    }
    else
    {
        _sprite.setScale(_scaleRatio, _scaleRatio);
    }

    frameIndex = { 0, 1, 2, 3 };

    currentFrame = firstFrame;

    _sprite.setTextureRect(frames[frameIndex[currentFrame]]);
}

void Animation::Animate(float animSpeed)
{
    if (clock.getElapsedTime().asSeconds() >= animSpeed)
    {
        currentFrame = (currentFrame + 1) % frameIndex.size();
        _sprite.setTextureRect(frames[frameIndex[currentFrame]]);
        clock.restart();
    }
}