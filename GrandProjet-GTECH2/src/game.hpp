#include <SFML/Graphics.hpp>
#include "scene/SceneManager.hpp"

class Game {
public:
	Game();
	~Game();

	void GameLoop();

private:
	SceneManager* sm;
	sf::RenderWindow* window;
	sf::Event* event;
};