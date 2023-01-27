#include "Scene.hpp"

Scene::Scene() {
	
}

Scene::~Scene() {

}

void Scene::Update(sf::Event* event, sf::RenderWindow* window) {
	/*this->Loop(event);
	this->Render(window);*/

	for (auto i = *std::end(this->layers); i >= *std::begin(this->layers); i--) {
		if (i->objects.empty() == false) {
			std::for_each(i->objects.begin(), i->objects.end(), [event, window](GameObject* obj) {
				obj->Update(event, window);
			});
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
	if (this->layers[layer] == nullptr) {
		AddLayer(layer);
	}

	this->layers[layer]->objects.push_back(&gameObject);
}

void Scene::AddLayer(int newLayer) {
	this->layers[newLayer] = new Layer;
}