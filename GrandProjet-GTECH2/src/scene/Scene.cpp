#include "Scene.hpp"

Scene::Scene() {

}

Scene::~Scene() {

}

void Scene::AddLayer(Layer* layer) {
	layers.push_back(layer);
}

void Scene::Draw() {

}