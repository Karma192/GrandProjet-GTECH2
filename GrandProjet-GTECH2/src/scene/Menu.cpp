#include "Menu.hpp"

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::MenuLoop(sf::Event* event) {
	
}

void Menu::MenuRender(sf::RenderWindow* window) 
{
	menuhud.menuRender(window);
	menuhud.menuSelection(window);
	menuhud.menuTitle(window);
	if (menuhud.once == true) {
		menuhud.menuTxt(window);
	}
	else {
		std::cout << "test";
	}
}