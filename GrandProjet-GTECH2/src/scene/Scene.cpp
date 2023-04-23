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
	Init();
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

void GameScene::Init()
{
	// code here
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
					if (layers[i]->objects[j]->IsDestructed())
					{
						delete layers[i]->objects[j];
						layers[i]->objects.erase(layers[i]->objects.begin() + j);
					}
					else {
						layers[i]->objects[j]->Update();
					}
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