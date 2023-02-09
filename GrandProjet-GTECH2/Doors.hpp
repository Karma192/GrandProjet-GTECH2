#pragma once
#include "src/GameObject.hpp"


class Doors : public GameObject 
{
public:
	Doors();
	~Doors();

	virtual void Loop()override;
	virtual void Render()override;

	sf::RectangleShape exit;


};

