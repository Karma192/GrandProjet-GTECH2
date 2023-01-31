#include "Menu.hpp"

Menu::Menu() {
	/*player = new Player;
	enemies = new Enemies();*/
	AddToScene(menu, 0);
}

Menu::~Menu() {

}

void Menu::Loop() {

}

void Menu::Render()
{
	menu.Render();
	//player->PlayerTest();
	//enemies->EnemiesTest();
	//collision.GetBounds();
}