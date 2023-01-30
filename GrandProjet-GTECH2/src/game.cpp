#include "Game.hpp"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Crusade Of The Abyss");
sf::Event event;
//sf::Image icon;

SceneManager sm;

void Game() {
    //icon.loadFromFile("ICON.png");
    //window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sm.SetSM(&window, &event);

    while (window.isOpen())
    {
        GameLoop();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                SetActiveScene(1);
            }
        }
    }
}

// Game's Loop
void GameLoop() {
    window.clear();
    sm.Update();
    window.display();
}