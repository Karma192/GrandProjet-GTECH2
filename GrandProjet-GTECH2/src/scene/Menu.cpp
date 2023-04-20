#include "Menu.hpp"
#include "../Instance/Camera.hpp"
#include "../Instance/PhysicsManager.hpp"

Menu::Menu() 
{
	menuhud = new menuHUD();
	AddToScene(menuhud, 0);
}

Menu::~Menu() 
{
	PhysicsManager::GetInstance()->RemoveBody(menuhud);
}

void Menu::Init()
{
	Camera::GetInstance()->ResetCamera();
}
