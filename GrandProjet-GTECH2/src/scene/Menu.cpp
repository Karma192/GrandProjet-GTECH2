#include "Menu.hpp"

Menu::Menu() {
	AddToScene(&menuhud, 0);
}

Menu::~Menu() {

}

void Menu::Loop() {

}

void Menu::Render()
{
	menuhud.Render();
}