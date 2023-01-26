#include "Menu.hpp"

Menu::Menu() {
	player = new Player;
	enemies = new Enemies();
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
	player->PlayerRender(window);
	//player->PlayerTest(window);
	//enemies->EnemiesTest(window);
	//collision.GetBounds();
}