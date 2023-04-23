#include "CollisionManager.h"

CollisionManager::CollisionManager() {
}

CollisionManager::~CollisionManager() {}

void CollisionManager::addObject(CollisionObject* object) {
    objects_.push_back(object);
}

void CollisionManager::removeObject(CollisionObject* object) {
    // Recherche de l'objet dans la liste
    auto it = std::find(objects_.begin(), objects_.end(), object);
    if (it != objects_.end()) {
        // Suppression de l'objet
        objects_.erase(it);
    }
}

void CollisionManager::updateCollisions() {
    // Parcours de tous les objets de la liste
    for (auto i = objects_.begin(); i != objects_.end(); i++) {
        CollisionObject* object1 = *i;

        // Parcours des objets suivants dans la liste
        for (auto j = i + 1; j != objects_.end(); j++) {
            CollisionObject* object2 = *j;

            // Test de collision entre object1 et object2
            if (object1->collidesWith(object2)) {
                // Gestion de la collision
                object1->handleCollision(object2);
                object2->handleCollision(object1);
            }
        }
    }
}
