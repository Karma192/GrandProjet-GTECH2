#include  "InGame.hpp"
#include "../Camera.hpp"

InGame::InGame() {

}

InGame::~InGame() {

}

void InGame::Loop() {
	Camera::GetInstance()->ResetCamera();
}

void InGame::Render() {

}