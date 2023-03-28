#pragma once
#include "GameObject.hpp"

GameObject::GameObject()
{
	gameData = GameMaster::GetInstance()->GetGameData();
}

GameObject::~GameObject() 
{

}

void GameObject::SetID(std::string name, std::string tag)
{
	_name = name;
	SetCollideTag(tag);
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
