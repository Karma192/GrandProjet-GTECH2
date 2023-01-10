#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>

class GameObject {
public :
	int id;

	GameObject();
	~GameObject();

	// Boucle du game object
	void Update(sf::Event*, sf::RenderWindow*);
	// Processus en back du game object
	virtual void Loop(sf::Event*);
	// Rendu du game object
	virtual void Render(sf::RenderWindow*);
};