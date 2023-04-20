#include "Menu.hpp"
#include "../Instance/Camera.hpp"

Menu::Menu() 
{
	menuhud = new menuHUD();
	AddToScene(menuhud, 0);
}

Menu::~Menu() 
{
	delete menuhud;
}

void Menu::Init()
{
	Camera::GetInstance()->ResetCamera();
}
