#pragma once
#include <iostream>
#include "Scene.hpp"

class InGame : public GameScene {
public:
	InGame();
	virtual ~InGame();

	virtual void Loop()override;
	virtual void Render()override;

private:

};