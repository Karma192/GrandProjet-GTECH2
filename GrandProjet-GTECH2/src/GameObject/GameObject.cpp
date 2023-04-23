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

void GameObject::SetSprite(std::string spriteFile, sf::Vector2f scale)
{
	bool isDebug = spriteFile == "Debug";
	bool isWall = spriteFile == "Wall";
	bool isDefault = spriteFile == "Default";

	if (isWall) 
	{
		_sprite->setTextureRect(sf::IntRect(0, 0, 16, 16));
		_sprite->setTexture(sf::Texture());
		_sprite->setColor(sf::Color::Red);
	}
	else {
		if (isDebug) // Debug
		{
			_sprite->setTextureRect(sf::IntRect(10, 10, 10, 10));
			_sprite->setTexture(sf::Texture());
			_sprite->setColor(sf::Color::Red);
		}
		else if (isDefault) // Default
		{
			_sprite->setTextureRect(sf::IntRect(0, 0, 10, 10));
			_sprite->setTexture(sf::Texture());
			_sprite->setColor(sf::Color::White);
		}
		else // GameObject Standard
		{
			sf::Texture text = sf::Texture();
			text.loadFromFile(_path + spriteFile);
			_sprite->setTexture(text);
		}
		_sprite->scale(scale.x, scale.y);
		_sprite->setOrigin(_sprite->getLocalBounds().width / 2.0f,
			_sprite->getLocalBounds().height / 2.0f);
	}
}

void GameObject::SetPosition(sf::Vector2f position)
{
	_sprite->setPosition(position);
}
