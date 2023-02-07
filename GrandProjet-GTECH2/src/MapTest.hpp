#include <tmxlite/Map.hpp>
#include "GameObject.hpp"
#include "../../SFMLExample/src/SFMLOrthogonalLayer.hpp"

class Map : public GameObject 
{
public:
	Map();
	virtual ~Map();

	virtual void Render()override;

private:
	tmx::Map village;

	MapLayer* layerZero;
	MapLayer* layerOne;
	MapLayer* layerTwo;
};