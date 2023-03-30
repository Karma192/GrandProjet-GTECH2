#pragma once
#include "GameObject.hpp"
#include "GameMaster.hpp"

GameObject::GameObject()
{
	SetData();
	GameMaster::AddGameObject(this);
	_destructed = false;
}

GameObject::~GameObject()
{

}

void GameObject::Update()
{
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
	_destructed = true;
}

void GameObject::SetData()
{
	srand(time(0));
}
