#include <iostream>
#include "Scene.hpp"

class InGame : public Scene {
public:
	SceneManager* sm;

	InGame();
	InGame(SceneManager*);
	virtual ~InGame();

	void InGameLoop(sf::Event*);
	void InGameRender(sf::RenderWindow*);

private:

};