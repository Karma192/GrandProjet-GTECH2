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
	for (int i = 0; i < 10; i++) 
	{
		if (layers[i] != nullptr) 
		{
			for (int j = 0; j < layers[i]->objects.size(); j++) 
			{
				if (layers[i]->objects[j] != nullptr) 
				{
					layers[i]->objects[j]->Update();
				}
			}
		}
	}
}

void GameScene::Loop()
{

}

void GameScene::Render()
{

}

void GameScene::AddToScene(GameObject* gameObject, int layer)
{
	if (layers[layer] == nullptr)
	{
		layers[layer] = new Layer();
	}

	layers[layer]->objects.push_back(gameObject);
}

void GameScene::SetLayer()
{
	for (int i = 0; i < 10; i++)
	{
		layers[i] = nullptr;
	}
}