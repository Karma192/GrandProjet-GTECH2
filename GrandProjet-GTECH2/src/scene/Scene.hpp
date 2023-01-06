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
	
	void AddLayer(Layer*);
	void Draw();
};