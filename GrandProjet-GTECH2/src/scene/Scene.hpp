#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../GameObject/GameObject.hpp"
#include "../Instance/GameMaster.hpp"

class Layer {
public:
	Layer();

	std::vector <GameObject*> objects = { nullptr };
};

class GameScene {
public:
	GameScene();
	virtual ~GameScene();

	void InitializeScene();

	// Boucle de la scene
	void Update();
	// Processus en back spécifique a la scene
	virtual void Loop();
	// Rendu graphique spécifique a la scene
	virtual void Render();
	// Permet d'ajouter un game object à la scene à un certain layer (0 étant le plus profond)
	void AddToScene(GameObject*, int);

private:
	bool _init = false;
	Layer* layers[10];

	// Fonction pour tout les layers de la scene a NULL
	void SetLayer();
};
