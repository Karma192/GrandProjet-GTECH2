#include "Menu.hpp"

Menu::Menu() {
	AddToScene(menu, 0);
}

Menu::~Menu() {

}

void Menu::Loop() {

}

void Menu::Render()
{
	/*menuhud.menuRender(window);
	menuhud.menuSelection(window);
	menuhud.menuTitle(window);
	if (menuhud.once == true) {
		menuhud.menuTxt(window);
	}
	else {
		menuhud.Volume(window);
		menuhud.GoBack(window);
		menuhud.ChangeResolution(window);
		menuhud.Language(window);
	}*/
  
	menu.Render();
	//player->PlayerTest();
	//enemies->EnemiesTest();
	//collision.GetBounds();
}