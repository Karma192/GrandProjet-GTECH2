#include "Scene.hpp"

Scene::Scene() {
	
}

Scene::~Scene() {

}

void Scene::Update(sf::Event* event, sf::RenderWindow* window) {
	Loop(event);
	Render(window);
}

void Scene::Render(sf::RenderWindow* window) {
	for (int i = sizeof(this->layers); i > 0; i--) {
		if (this->layers[i] != nullptr) {
			for (int j = 0; j < sizeof(this->layers[i]->objects); j++) {
				if (this->layers[i]->objects[j] == NULL) {
					std::cout << "Pas d'objets sur ce layer !" << std::endl;
				}
				else {
					this->layers[i]->objects[j]->Render(window);
				}
			}
		}
	}
}

void Scene::Loop(sf::Event* event) {
	for (int i = sizeof(this->layers); i > 0; i--) {
		if (this->layers[i] != nullptr) {
			for (int j = 0; j < sizeof(this->layers[i]->objects); j++) {
				if (this->layers[i]->objects[j] == NULL) {
					std::cout << "Pas d'objets sur ce layer !" << std::endl;
				}
				else {
					this->layers[i]->objects[j]->Loop(event);
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