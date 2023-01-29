#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SceneManager.hpp"
#include "../GameObject.hpp"

class Layer {
public:
	Layer();

	std::vector <GameObject*> objects;
};


class Scene {
public:
	int x;

	Scene();
	virtual ~Scene();

	// Boucle de la scene
	void Update(sf::Event*, sf::RenderWindow*);
	// Rendu graphique de la sc�ne
	virtual void Render(sf::RenderWindow*);
	// Processus en back de la sc�ne
	virtual void Loop(sf::Event*);
	// Permet d'ajouter un game object � la sc�ne � un certain layer (0 �tant le plus profond)
	void AddToScene(GameObject&, int);

private:
	//SceneManager* sm;
	sf::Event* event;
	sf::RenderWindow* window;

	Layer* layers[10] = { nullptr };

	// Creer un layer dans la sc�ne (max 10/scene)
	void SetLayer();
};