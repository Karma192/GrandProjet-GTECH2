#include "Camera.hpp"

Camera* Camera::_instance = nullptr;
sf::RectangleShape* Camera::_target = nullptr;

Camera::Camera()
{
	_offset = 0;
	_cameraView = GameMaster::GetGameData().window->getDefaultView();

	if (_instance == nullptr && _instance != this)
	{
		_instance = this;
	}
}

void Camera::Update()
{
	if (_target != nullptr)
	{
		_cameraView.setCenter(_target->getPosition());
	}

	GameMaster::GetGameData().window->setView(_cameraView);
}

Camera* Camera::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Camera();
	}
	return _instance;
}

void Camera::SetFollow(sf::RectangleShape* tar)
{
	_target = tar;
}

void Camera::ResetCamera()
{
	_target = nullptr;
	float posx = GameMaster::GetGameData().window->getSize().x / 2.0f;
	float posy = GameMaster::GetGameData().window->getSize().y / 2.0f;
	_cameraView.setCenter(sf::Vector2f(posx, posy));
}

void Camera::SetPosCamera(float x, float y)
{
	_target = nullptr;
	_cameraView.setCenter(sf::Vector2f(x, y));
}

void Camera::SetCameraOffset(int value)
{
	_offset = value;
}
