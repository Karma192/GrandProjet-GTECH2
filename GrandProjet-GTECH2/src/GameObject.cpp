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
	gameData = GameMaster::GetInstance()->GetGameData();
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

	// à tester avec CHASSAING
	//delete& list[0];
}

void GameObject::SetData()
{
	srand(time(0));
	id = rand();
	gameData = GameMaster::GetInstance()->GetGameData();
}
