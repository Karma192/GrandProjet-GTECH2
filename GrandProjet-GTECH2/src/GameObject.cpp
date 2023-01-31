#pragma once
#include "GameObject.hpp"

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
	srand(time(0));
	id = rand();
}