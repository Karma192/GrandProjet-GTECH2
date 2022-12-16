#include <iostream>
#include "Scene.hpp"

class InGame : public Scene {
public:
	InGame();
	virtual ~InGame();

	void InGameLoop();
	void InGameRender(sf::RenderWindow*);

private:

};