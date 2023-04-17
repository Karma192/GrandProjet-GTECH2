#include "GameObject.hpp"
#include "../Instance/GameMaster.hpp"

GameObject::GameObject()
{
	_destructed = false;
	_init = false;
	GameMaster::GetInstance()->AddGameObject(this);
}

GameObject::~GameObject()
{

}

void GameObject::SetID(std::string name, std::string tag)
{
	_name = name;
	SetCollideTag(tag);
}

void GameObject::Init()
{
	DefineOwnBody(this);
	_init = true;
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