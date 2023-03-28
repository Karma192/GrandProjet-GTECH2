#include "GameObject.hpp"
#include "Player.hpp"

class ToNextScene : public GameObject
{
public:
	ToNextScene();
	ToNextScene(int, sf::Sprite, int, int);
	virtual ~ToNextScene();

	void Loop()override;
	void Render()override;

	bool collidesWith(CollisionObject* other) override;
	void handleCollision(CollisionObject* other) override;
	sf::Sprite _sprite;
private:
	int scene;

	void GoToScene();
};