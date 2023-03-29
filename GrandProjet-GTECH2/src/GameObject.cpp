#pragma once
#include "GameObject.hpp"

GameObject::GameObject() 
{
	SetData();
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

void GameObject::Destroy() 
{
	std::vector<GameObject*> list;
	list.push_back(this);
	list.clear();
}

void GameObject::SetData()
{
	srand(time(0));
	id = rand();
	gameData = GetGameData();
}
