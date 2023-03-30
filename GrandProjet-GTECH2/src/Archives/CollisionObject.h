#pragma once
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

class CollisionObject {
public:
    virtual bool collidesWith(CollisionObject* other) = 0;
    virtual void handleCollision(CollisionObject* other) = 0;
};
