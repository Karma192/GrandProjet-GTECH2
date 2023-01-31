#include "Game.hpp"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Crusade Of The Abyss");
sf::Event event;


void Game() 
{
    SetWindow(&window, &event);
    SceneManager sm;
    sm.SetSM(&window, &event);

    while (window.isOpen())
    {
        GameLoop(sm);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
               sm.smData = GetGameData();
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