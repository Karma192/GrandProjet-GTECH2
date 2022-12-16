#include <iostream>
#include "Scene.hpp"

class Menu : public Scene {
public:
	Menu();
	virtual ~Menu();
	void MenuLoop();
	void MenuRender();

private:

};