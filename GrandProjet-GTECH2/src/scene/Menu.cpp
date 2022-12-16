#include "Menu.hpp"


Menu::Menu() 
{

}

Menu::Menu(SceneManager* sceneM) {
	sm = sceneM;
}

Menu::~Menu() {

}

void Menu::MenuLoop(sf::Event* event) {

}

void Menu::MenuRender(sf::RenderWindow* window) 
{
	test.PlayerRender(window);

}