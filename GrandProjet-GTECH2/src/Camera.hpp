#pragma once

#include <stdio.h>
#include<SFML/Window.hpp>
#include "GameObject.hpp"

class Camera
{
protected:
	static Camera* _instance;
	static sf::Sprite* _target;
	sf::View _cameraView;

	int _delay;
public:
	Camera();
	Camera(Camera& other) = delete;

	void operator=(const Camera&) = delete;

	void Update();

	static Camera* GetInstance();
	void SetFollow(sf::Sprite*);
	void ResetCamera();
	void SetPosCamera(float, float);
	void SetCameraDelay(int);
};