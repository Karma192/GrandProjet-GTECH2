#include "Game.hpp"
#include "Spell.hpp"

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Crusade Of The Abyss");
sf::Event event;
//sf::Image icon;

SceneManager sm;
Player p;

void Game() {
    //icon.loadFromFile("ICON.png");
    //window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sm.SetSM(&window, &event);
    Spell spell;

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
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                spell.cast();
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