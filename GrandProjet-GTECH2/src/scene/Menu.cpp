#include "Menu.hpp"

Menu::Menu() {
}

Menu::~Menu() {

}

void Menu::Loop(sf::Event* event) {

}

void Menu::Render(sf::RenderWindow* window)
{

	menu.menuRender(window);
	menu.menuSelection(window);
	menu.menuTitle(window);
}