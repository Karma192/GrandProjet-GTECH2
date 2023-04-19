#include "GameObject.hpp"
#include "../Instance/GameMaster.hpp"

int GameObject::_number = 0;

GameObject::GameObject()
{
	_destructed = false;
	_init = false;
	_sprite = new sf::Sprite();
	_name = "GameObject";

	_id = _number;
	_number++;
}

GameObject::~GameObject()
{
	delete _sprite;
}

void GameObject::Create()
{
	GameMaster::GetInstance()->AddGameObject(this);
	Init();
	DefineOwnBody(this);
	_init = true;
}

void GameObject::SetID(std::string name, std::string tag) 
{
	_name = name;
	SetCollideTag(tag);
}

void GameObject::Init()
{
	// Code here
}

void GameObject::Update()
{
	this->Loop();
	this->Render();
}

void GameObject::Loop()
{

}

void GameObject::Render()
{

}

void GameObject::Destroy()
{
	_destructed = true;
}

void GameObject::SetSprite(std::string filePath, sf::Vector2f scale)
{
	sf::Texture text = sf::Texture();
	text.loadFromFile(_path + filePath);

	_sprite->setTexture(text);
	_sprite->scale(scale.x, scale.y);
	_sprite->setPosition(sf::Vector2f(200, 200));

	_sprite->setOrigin(GetBounds()->width / 2.0f, GetBounds()->height / 2.0f);
}

void GameObject::SetPosition(sf::Vector2f position)
{
	_sprite->setPosition(position);
}
