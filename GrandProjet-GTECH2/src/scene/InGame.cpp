#include  "InGame.hpp"
#include "../Instance/Camera.hpp"

InGame::InGame() {

}

InGame::~InGame() {

}

void InGame::Init()
{
	Camera::GetInstance()->ResetCamera();
}
