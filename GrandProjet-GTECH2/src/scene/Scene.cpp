#include "Scene.hpp"

Layer::Layer() 
{
	
}

GameScene::GameScene() 
{
	SetLayer();
}

GameScene::~GameScene() 
{

}

void GameScene::InitializeScene()
{
	for (int i = 0; i < 10; i++)
	{
		if (layers[i] != nullptr)
		{
			for (int j = 0; j < layers[i]->objects.size(); j++)
			{
				if (layers[i]->objects[j] != nullptr)
				{
					layers[i]->objects[j]->Create();
				}
			}
		}
	}
}

void GameScene::Update() 
{
	if (!_init)
	{
		InitializeScene();
		_init = true;
	}

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

	this->Loop();
	this->Render();
}

void GameScene::Loop()
{
	// code here
}

void GameScene::Render()
{
	// code here
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