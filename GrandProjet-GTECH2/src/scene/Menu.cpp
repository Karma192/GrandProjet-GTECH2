#include "Menu.hpp"

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::MenuLoop(sf::Event* event) {
	
}

void Menu::MenuRender(sf::RenderWindow* window) 
{
	menu.menuRender(window);
	menu.menuSelection(window);
	menu.menuTitle(window);
}