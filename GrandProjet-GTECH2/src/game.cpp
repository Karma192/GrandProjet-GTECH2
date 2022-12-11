#include "game.hpp"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Crusade Of The Abyss");

void Game() {
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

}

// All Things to Render
void GameRender() {
    window.clear();
    // things to display
    window.display();
}