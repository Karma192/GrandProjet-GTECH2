#pragma once
#include "GameObject.hpp"

GameObject::GameObject() {
	srand(time(0));
	id = rand();
	gameData = GetGameData();
}

GameObject::~GameObject() {

}

void GameObject::InitGameData() {

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