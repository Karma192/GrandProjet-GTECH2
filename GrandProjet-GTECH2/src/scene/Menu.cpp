#include "Menu.hpp"

Menu::Menu() {
	player = new Player;
}

Menu::~Menu() {

}

void Menu::MenuLoop(sf::Event* event) {
	
}

void Menu::MenuRender(sf::RenderWindow* window) 
{
	player->PlayerRender(window);
	player->PlayerTest(window);
}