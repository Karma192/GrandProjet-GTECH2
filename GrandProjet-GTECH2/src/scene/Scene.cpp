#include "Scene.hpp"

Layer::Layer() {
	this->objects.push_back(nullptr);
}

Scene::Scene() {
	SetLayer();
}

Scene::~Scene() {

}

void Scene::Update(sf::Event* event, sf::RenderWindow* window) {
	/*this->Loop(event);
	this->Render(window);*/

	for (int i = 9; i > 0; i--) {
		if (layers[i] != nullptr) {
			for (int j = 0; j < layers[i]->objects.size(); j++) {
				if (layers[i]->objects[j] != nullptr) {
					layers[i]->objects[j]->Update(event, window);
				}
			}
		}
	}

}

void Scene::Render(sf::RenderWindow* window) {
	for (auto i = *std::prev(std::end(this->layers)); i >= *std::begin(this->layers); i--) {
		if (i->objects.empty() == false) {
			for (int j = 0; j < (i->objects.size() - 1); j++) {
				if (i->objects[j] != NULL) {
					//i->objects[j]->Render(window);
				}
			}
		}
	}
}

void Scene::Loop(sf::Event* event) {
	for (auto i = *std::prev(std::end(this->layers)); i >= *std::begin(this->layers); i--) {
		if (i->objects.empty() == false) {
			for (int j = 0; j < (i->objects.size() - 1); j++) {
				if (i->objects[j] != NULL) {
					//i->objects[j]->Loop(event);
				}
			}
		}
	}
}

void Scene::AddToScene(GameObject& gameObject, int layer) {
	layers[layer]->objects.push_back(&gameObject);
}

void Scene::SetLayer() {
	for (int i = 0; i < 9; i++) {
		layers[i] = new Layer;
	}
}