#pragma once
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "CollisionObject.h"

class CollisionManager  {
private:
    std::vector<CollisionObject*> objects_; 

public:
    CollisionManager();
    ~CollisionManager();

    void addObject(CollisionObject* object);
    void removeObject(CollisionObject* object);
    void updateCollisions();
};

