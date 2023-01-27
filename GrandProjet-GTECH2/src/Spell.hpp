#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

// The spell class
class Spell {
private:
    // The current cooldown of the spell
    int cooldown;
    // The maximum cooldown of the spell
    int maxCooldown;

public:
    Spell() : cooldown(0), maxCooldown(10) {}

    // Update the spell's cooldown
    void update() {
        if (cooldown > 0) {
            // Decrement the cooldown
            cooldown--;
        }
    }

    // Cast the spell
    void cast() {
        if (cooldown == 0) {
            // Reset the cooldown
            cooldown = maxCooldown;
            // Do something when the spell is cast
            std::cout << "Casting spell!" << std::endl;
        }
    }

    // Draw the spell's cooldown bar
    void draw(sf::RenderWindow& window) {
        sf::RectangleShape bar(sf::Vector2f(100, 20));
        bar.setFillColor(sf::Color(100, 100, 100));
        bar.setPosition(0, 0);
        window.draw(bar);

        if (cooldown > 0) {
            sf::RectangleShape cooldownBar(sf::Vector2f(cooldown / maxCooldown * 100, 20));
            cooldownBar.setFillColor(sf::Color(150, 150, 150));
            cooldownBar.setPosition(0, 0);
            window.draw(cooldownBar);
        }
    }
};
