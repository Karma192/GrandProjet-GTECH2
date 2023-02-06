#pragma once
#include "GameObject.hpp"

GameObject::GameObject() 
{
	srand(time(0));
	id = rand();
	gameData = GetGameData();
}

GameObject::~GameObject() 
{

}

void GameObject::Update() 
{
	gameData = GetGameData();
	this->Loop();
	this->Render();
}

void GameObject::Loop() 
{

}

void GameObject::Render() 
{

}
