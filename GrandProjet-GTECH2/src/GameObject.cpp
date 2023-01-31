#pragma once
#include "GameObject.hpp"

GameObject::GameObject() {
	srand(time(0));
	id = rand();
}

GameObject::~GameObject() {

}

void GameObject::Init() {

}

void GameObject::Update() {
	this->Loop();
	this->Render();
}

void GameObject::Loop() {

}

void GameObject::Render() {

}


void GameObject::InitGameData() 
{
	gameData = GetGameData();
}