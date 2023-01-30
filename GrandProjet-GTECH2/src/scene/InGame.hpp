#pragma once
#include <iostream>
#include "Scene.hpp"

class InGame : public GameScene {
public:
	InGame();
	virtual ~InGame();

	virtual void Loop(sf::Event*)override;
	virtual void Render(sf::RenderWindow*)override;

private:

};