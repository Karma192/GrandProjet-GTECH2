#include "Game.hpp"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Crusade Of The Abyss");
sf::Event event;

SceneManager sm;

void Game() {
    sm.SetSM(&window, &event);

    while (window.isOpen())
    {
        GameLoop();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sm.SetActiveScene(1);
            }
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