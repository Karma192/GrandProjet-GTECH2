#include "GameObject.hpp"
#include "../Instance/GameMaster.hpp"

GameObject::GameObject(GameObject* self) : PhysicBody(self)
{
	GameMaster::AddGameObject(this);
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