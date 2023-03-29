#pragma once
#include "GameObject.hpp"
#include "GameMaster.hpp"

GameObject::GameObject()
{
	SetData();
	//GameMaster::AddGameObject(this);
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
	/*std::vector<GameObject*>& list = GameMaster::GetInstance()->GetListGameObject();
	auto it = std::find(list.begin(), list.end(), this);
	if (it != list.end()) {
		list.erase(it);
	}
	delete this;*/
}

void GameObject::SetData()
{
	srand(time(0));
	id = rand();
}
