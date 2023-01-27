#include "GameObject.hpp"

class Example : public GameObject {
public :
	Example();
	~Example();

	virtual void Loop(sf::Event*);
	virtual void Render(sf::RenderWindow*);
};