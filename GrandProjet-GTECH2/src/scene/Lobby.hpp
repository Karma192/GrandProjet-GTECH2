#include <iostream>
#include "Scene.hpp"

class Lobby : public Scene {
public:
	Lobby();
	virtual ~Lobby();
	void LobbyLoop();
	void LobbyRender(sf::RenderWindow*);

private:

};