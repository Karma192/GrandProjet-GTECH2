#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "../GameObject.hpp"
#include <chrono>

class Player;

class Spell : public GameObject
{
public:
	Spell() = default;
	virtual ~Spell() { delete _cooldown; delete _player; }

	// Struct de cooldown
	struct Cooldown
	{
		int _cooldown;
		int _maxCooldown;

		Cooldown(int maxCooldown) : _cooldown(0), _maxCooldown(maxCooldown) {}

		bool IsReady() { return _cooldown <= 0; }
		void Update() { _cooldown--; }
		void Reset() { _cooldown = _maxCooldown; }
	};

	// Fonction pour utiliser le sort
	void Use() { Reset(); _cooldown->Reset(); }
	// Fonction pour reinitialiser le sort
	void Reset();

	// Fonction executer à l'activation du sort
	virtual void OnActive() { _isInit = true; }
	// Fonction executer à la réinitialisation du sort
	virtual void Reinitialize() {}
	// Fonction executer quand le sort est inactif
	virtual void InactiveUpdate() {}

	// Fonction pour mettre à jour le sort
	void SpellUpdate()
	{
		if (!IsDestroyed() && IsActive())
		{
			if (!_isInit)
				OnActive();

			if (_lifeTime > 0)
				UpdateLifeTime();
			else
				_destroyed = true;

			Loop();
			Render();
		}
		else {
			SetPosition(sf::Vector2f(-100000, -100000));
			InactiveUpdate();
		}
		_cooldown->Update();
	}

	virtual void Loop()override {}
	virtual void Render()override {}

	virtual void OnCollisionEnter(PhysicBody* other)override {}

	// Fonction pour définir le pointeur vers le player
	void SetPlayer(Player* player) { _player = player; }

	// Fonction pour retouner le cooldown
	Cooldown* GetCooldown() { return _cooldown; }
	// Fonction pour retourner si le sort est détruit
	bool IsDestroyed() { return _destroyed; }
	// Fonction pour retourner si le sort est actif
	bool IsActive() { return _isActive; }

private:
	// Fonction pour mettre à jour la durée de vie du sort
	void UpdateLifeTime() { _lifeTime--; }

protected:
	// Fontcion pour définir la durée de vie du sort
	void SetLifeTime(int lifeTime) { _lifeTime = lifeTime; _maxLifeTime = lifeTime; }

	Cooldown* _cooldown;

	Player* _player;

	int _lifeTime = 0;
	int _maxLifeTime = 0;
	bool _isInit = false;
	bool _isActive = false;
	bool _destroyed = false;
};

class FireBall : public Spell
{
public:
	FireBall() = default;
	FireBall(sf::Vector2f pos);
	virtual ~FireBall();

	virtual void Loop()override;
	virtual void Render()override;

	virtual void OnCollisionEnter(PhysicBody* other)override;

	// Fonction pour définir la direction de la boule de feu
	void SetDirection(sf::Vector2f dir);

private:
	sf::Vector2f _position;
	sf::Vector2f _direction;
	float _speed = 20;
};

class Dash :public Spell
{
public:
	Dash();
	virtual ~Dash();

	virtual void OnActive()override;

	virtual void InactiveUpdate()override;

	// Fonction pour définir la force du dash
	void SetStrenght(float strenght);

private:
	float _strenght = 0.5f;
};

class ThirdSpell : public Spell
{
public:
	ThirdSpell();
	virtual ~ThirdSpell();

	virtual void Loop()override;
	virtual void Render()override;

	virtual void OnCollisionEnter(PhysicBody* other)override;
};

class SpellsManager
{
public:
	SpellsManager() = default;
	SpellsManager(Player* p);
	virtual ~SpellsManager();

	// Fonction d'update des sorts
	void UpdateSpell();

	// Fonction pour détruire les sorts
	void PurgeSpell();

private:
	// Fonction pour retourner la direction du lancement du sort
	sf::Vector2f LaunchDirection();
	// Fonction pour utiliser des sorts
	void CastSpell();

	Player* _player;

	// Keyboard check
	bool _shiftIsPressed = false;
	bool _spaceIsPressed = false;

	// Spells
	std::vector<Spell*> _spells;
	int _indexSpell;

	FireBall* _fireBallSpell;
	Dash* _dashSpell;
	ThirdSpell* _thirdSpell;

	sf::Vector2f _launchDirection;
};
