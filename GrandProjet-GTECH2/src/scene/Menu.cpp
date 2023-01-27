#include "Menu.hpp"

Menu::Menu() {
	player = new Player;
	enemies = new Enemies;
	AddToScene(menu, 0);
}

Menu::~Menu() {

}

//void Menu::Loop(sf::Event* event) {
//	
//}

void Menu::Render(sf::RenderWindow* window) 
{
	menu.menuRender(window);
	menu.menuSelection(window);
	menu.menuTitle(window);
	//player->PlayerRender(window);
	//player->PlayerTest(window);
	//enemies->EnemiesTest(window);
	/*collision.GetBounds();*/
}