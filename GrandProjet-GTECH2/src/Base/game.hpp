#include <SFML/Graphics.hpp>
#include "../Scene/SceneManager.hpp"

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