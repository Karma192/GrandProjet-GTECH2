#include "Animation.h"

void Animation::LoadAnimation(std::string filename, sf::Sprite *sprite, int frameWidth, int frameHeight, float scaleRatio)
{
    _scaleRatio = scaleRatio;
    _sprite = sprite;

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

    _sprite->setTexture(texture);
}

void Animation::SetAnimation(bool doFlip, int firstFrame)
{
    if (doFlip)
    {
        // to the right
        _sprite->setScale(-_scaleRatio, _scaleRatio);
    }
    else
    {
        // to the left
        _sprite->setScale(_scaleRatio, _scaleRatio);
    }

    frameIndex = { 0, 1, 2, 3 };

    frameIndexTest = { 8, 9, 10, 11, 12 };

    // first frame start to 0
    currentFrame = firstFrame;
    currentFrameTest = firstFrame;
}

void Animation::Animate(float animSpeed)
{
    if (clock.getElapsedTime().asSeconds() >= animSpeed)
    {
        currentFrame = (currentFrame + 1) % frameIndex.size();
        _sprite->setTextureRect(frames[frameIndex[currentFrame]]);
        clock.restart();
    }
}

void Animation::AnimateTest(float animSpeed)
{
    if (clock.getElapsedTime().asSeconds() >= animSpeed)
    {
        currentFrameTest = (currentFrameTest + 1) % frameIndexTest.size();
        _sprite->setTextureRect(frames[frameIndexTest[currentFrameTest]]);
        clock.restart();
    }
}