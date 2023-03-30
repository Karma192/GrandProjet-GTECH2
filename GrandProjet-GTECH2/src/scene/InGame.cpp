#include  "InGame.hpp"
#include "../Instance/Camera.hpp"

InGame::InGame() {

}

InGame::~InGame() {

}

void InGame::Loop() {
	Camera::GetInstance()->ResetCamera();
}

void InGame::Render() {

}