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
	//menu.Render(window);

	/*player->Render(window);
	player->PlayerTest(window);*/
	//enemies->EnemiesTest(window);
	/*collision.GetBounds();*/
}