#include <iostream>
#include <SFML/Graphics.hpp>

class Enemies {
public:
	Enemies();
	~Enemies();
	void EnemiesLoop();
	void EnemiesRender();
	void EnemiesTest(sf::RenderWindow* window);

	sf::Texture enemiesTexture;
	sf::Sprite enemiesSprite;

private:

};