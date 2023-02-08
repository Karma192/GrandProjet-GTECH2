#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include "GameObject.hpp"
#include "../../SFMLExample/src/SFMLOrthogonalLayer.hpp"

class Map : public GameObject 
{
public:
	Map();
	virtual ~Map();

	virtual void Render()override;

private:
	std::string path = "ressources/map/";
	tmx::Map village;

	MapLayer* layerZero;
	MapLayer* layerOne;
	MapLayer* layerTwo;
};