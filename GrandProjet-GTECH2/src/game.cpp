#include "game.hpp"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Crusade Of The Abyss");

SceneManager sm;

void Game() {
    sm.SetSM(&window);

    while (window.isOpen())
    {
        sf::Event event;
        GameLoop();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        GameRender();
    }
}

// Game's Loop
void GameLoop() {
    sm.SceneManagerLoop();
}

// All Things to Render
void GameRender() {
    window.clear();
    sm.SceneManagerRender();
    // things to display
    window.display();
}