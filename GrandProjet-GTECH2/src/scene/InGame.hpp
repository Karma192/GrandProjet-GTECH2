#pragma once
#include <iostream>
#include "Scene.hpp"

class InGame : public Scene {
public:
	InGame();
	virtual ~InGame();

	void InGameLoop(sf::Event*);
	void InGameRender(sf::RenderWindow*);

private:

};