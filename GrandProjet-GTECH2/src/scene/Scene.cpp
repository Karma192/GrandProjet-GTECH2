#include "Scene.hpp"

Layer::Layer() {
	this->objects.push_back(nullptr);
}

GameScene::GameScene() {
	SetLayer();
}

GameScene::~GameScene() {

}

void GameScene::Update() {
	gameData = GameMaster::GetInstance()->GetGameData();
	this->Loop();
	this->Render();
	/*if (layers != nullptr) {
		for (int i = 9; i > 0; i--) {
			if (layers[i] != nullptr) {
				for (int j = 0; j < layers[i]->objects.size(); j++) {
					if (layers[i]->objects[j] != nullptr) {
						layers[i]->objects[j]->Update(event, window);
					}
				}
			}
		}
	}*/
}

void GameScene::Loop() {
	for (auto i = *std::prev(std::end(this->layers)); i >= *std::begin(this->layers); i--) {
		if (i->objects.empty() == false) {
			for (int j = 0; j < (i->objects.size() - 1); j++) {
				if (i->objects[j] != NULL) {
					i->objects[j]->Loop();
				}
			}
		}
	}
}

void GameScene::Render() {
	for (auto i = *std::prev(std::end(this->layers)); i >= *std::begin(this->layers); i--) {
		if (i->objects.empty() == false) {
			for (int j = 0; j < (i->objects.size() - 1); j++) {
				if (i->objects[j] != NULL) {
					i->objects[j]->Render();
				}
			}
		}
	}
}

void GameScene::AddToScene(GameObject* gameObject, int layer) {
	layers[layer]->objects.push_back(gameObject);
}

void GameScene::SetLayer() {
	for (int i = 0; i < 9; i++) {
		layers[i] = new Layer;
	}
}