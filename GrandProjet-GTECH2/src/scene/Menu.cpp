#include "Menu.hpp"
#include "../Instance/Camera.hpp"

Menu::Menu() {
	AddToScene(&menuhud, 0);
}

Menu::~Menu() {

}

void Menu::Loop() {
	Camera::GetInstance()->ResetCamera();
}

void Menu::Render()
{
	menuhud.Render();
}