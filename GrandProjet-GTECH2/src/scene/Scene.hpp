#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../GameObject.hpp"

class Layer {
public :
	std::vector <GameObject*> objects;
};


class Scene {
public :
	int x;

	Scene();
	virtual ~Scene();
	
	// Boucle de la scene
	void Update(sf::Event*, sf::RenderWindow*);
	// Rendu graphique de la scène
	virtual void Render(sf::RenderWindow*);
	// Processus en back de la scène
	virtual void Loop(sf::Event*);
	// Permet d'ajouter un game object à la scène à un certain layer (0 étant le plus profond)
	void AddToScene(GameObject&, int);
private:
	Layer* layers[10] = { nullptr };

	// Créer un layer dans la scène (max 10/scene)
	void AddLayer(int);
};