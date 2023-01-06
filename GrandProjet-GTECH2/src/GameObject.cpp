#include "GameObject.hpp"

GameObject::GameObject() {
	srand(time(0));

	id = rand();
}