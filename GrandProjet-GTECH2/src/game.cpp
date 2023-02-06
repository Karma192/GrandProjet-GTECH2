#include "Game.hpp"

Game::Game() {
    sm = new SceneManager;
    window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Crusade Of The Abyss", sf::Style::Titlebar);
    event = new sf::Event;
}

Game::~Game()
{

}

void Game::GameLoop()
{
    SetWindow(window, event);
    sm->SetSM(window, event);
    window->setFramerateLimit(60);

    while (window->isOpen())
    {
        window->clear();
        sm->Update();
        window->display();

        while (window->pollEvent(*event))
        {
            if (event->type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window->close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sm->smData = GetGameData();
                SetActiveScene(1);
            }
        }
    }
}

// Game's Loop
void GameLoop(SceneManager sm)
{
    window.clear();
    sm.Update();
    window.display();
 }