#include <iostream>
#include "Scene.hpp"
#include "../Player.hpp"

class Menu : public Scene {
public:
	SceneManager* sm;

	Menu();
	Menu(SceneManager*);
	virtual ~Menu();

	void MenuLoop(sf::Event*);
	void MenuRender(sf::RenderWindow*);

private:
	Player player;
};