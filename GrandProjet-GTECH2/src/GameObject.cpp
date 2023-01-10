#include "GameObject.hpp"

GameObject::GameObject() {
	srand(time(0));
	id = rand();
}

GameObject::~GameObject() {

}

void GameObject::Update(sf::Event* event, sf::RenderWindow* window) {
	this->Loop(event);
	this->Render(window);
}

void GameObject::Loop(sf::Event* event) {

}

void GameObject::Render(sf::RenderWindow* window) {

}