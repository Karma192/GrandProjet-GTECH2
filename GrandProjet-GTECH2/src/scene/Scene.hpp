#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../GameObject.hpp"

class Layer {
public:
	Layer();

	std::vector <GameObject*> objects;
};

class GameScene {
public:
	GameScene();
	virtual ~GameScene();

	// Boucle de la scene
	void Update(sf::Event*, sf::RenderWindow*);
	// Processus en back de la sc�ne
	virtual void Loop(sf::Event*);
	// Rendu graphique de la sc�ne
	virtual void Render(sf::RenderWindow*);
	// Permet d'ajouter un game object à la sc�ne à un certain layer (0 étant le plus profond)
	void AddToScene(GameObject&, int);
	// Creer un layer dans la sc�ne (max 10/scene)

private:
	sf::Event* event;
	sf::RenderWindow* window;

	Layer* layers[10] = { nullptr };

	void SetLayer();
};
