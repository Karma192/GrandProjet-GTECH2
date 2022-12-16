#include <iostream>
#include "Scene.hpp"

class Lobby : public Scene {
public:
	SceneManager* sm;

	Lobby();
	Lobby(SceneManager*);
	virtual ~Lobby();

	void LobbyLoop(sf::Event*);
	void LobbyRender(sf::RenderWindow*);

private:

};