#include "Menu.hpp"

Menu::Menu() {
	player = new Player;
	enemies = new Enemies();
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
	//player->PlayerTest(window);
	//enemies->EnemiesTest(window);
	//collision.GetBounds();
}