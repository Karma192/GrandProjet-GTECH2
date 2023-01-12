#pragma once
#include "Scene.hpp"

class Lobby : public Scene {
public:
	Lobby();
	virtual ~Lobby();

	virtual void Render(sf::RenderWindow*)override;

private:

};