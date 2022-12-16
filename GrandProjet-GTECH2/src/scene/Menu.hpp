#include <iostream>
#include "Scene.hpp"
#include "../Player.hpp"

class Menu : public Scene {
public:
	Menu();
	virtual ~Menu();
	void MenuLoop();
	void MenuRender(sf::RenderWindow* window);
	Player test;

private:

};