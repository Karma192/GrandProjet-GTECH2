#include "Game.hpp"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Crusade Of The Abyss", sf::Style::Fullscreen);
sf::Event event;
//sf::Image icon;

SceneManager sm;

void Game() {
    //icon.loadFromFile("ICON.png");
    //window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sm.SetSM(&window, &event);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        GameLoop();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
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