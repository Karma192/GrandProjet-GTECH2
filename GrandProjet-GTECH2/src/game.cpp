#include "Game.hpp"
#include <stdlib.h>

Game::Game() {
	sm = new SceneManager;
	window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Crusade Of The Abyss", sf::Style::Default);
	event = new sf::Event;
}

Game::~Game()
{

}

void Game::GameLoop()
{
	GameMaster::GetInstance()->SetWindow(window, event);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);

	while (window->isOpen())
	{
		window->clear();
		sm->Update();
		window->display();

		while (window->pollEvent(*event))
		{
			if (event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
			{
				window->close();
			}
		}
	}
}

