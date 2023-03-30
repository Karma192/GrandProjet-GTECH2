#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../GameObject/GameObject.hpp"
#include "../Instance/GameMaster.hpp"

class Layer {
public:
	Layer();

	std::vector <GameObject*> objects;
};

class GameScene {
public:
	GameScene();
	virtual ~GameScene();

	GameData gameData;

	// Boucle de la scene
	void Update();
	// Processus en back de la sc�ne
	virtual void Loop();
	// Rendu graphique de la sc�ne
	virtual void Render();
	// Permet d'ajouter un game object à la sc�ne à un certain layer (0 étant le plus profond)
	void AddToScene(GameObject*, int);

private:
	Layer* layers[10] = { nullptr };

	void SetLayer();
};
