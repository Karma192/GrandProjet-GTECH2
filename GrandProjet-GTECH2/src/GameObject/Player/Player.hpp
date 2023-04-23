#pragma once 

#define M_PI           3.14159265358979323846  /* pi */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <cmath>
#include "../GameObject.hpp"
#include "../Enemies.hpp"
#include "../../MapGenerator.hpp"
#include "../ToNextScene.hpp"
#include "Spells.hpp"
#include "../Animation.h"

class Player : public GameObject 
{
public:
	Player();
	virtual ~Player();

	virtual void Init()override;

	virtual void Loop()override;
	virtual void Render()override;

	virtual void OnCollisionEnter(PhysicBody* other)override;

	//Player HUD 
	void playerUI();

	//Player controller
	void MouseUsage();
	void ControllerMove();
	void MovePlayer();
	void KeyboardMove();

	//Player attributes
	sf::Vector2f GetPlayerPosition();

	// Fonction pour r�cuperer l'angle de vis�e du joueur
	float GetPlayerAimDegree();

	// Fonction pour ajouter une valeur au modificateur de vitesse
	void AddSpeedModifier(float value) { _modifierSpeed += value; }
	// Fonction pour r�initialiser le modificateur de vitesse
	void ResetSpeedModifier() { _modifierSpeed = 1; }

	//Player attack
	void PlayerAttack();
	void PlayerBasicAttack();

	// Lilian TEST

	Animation animation;

	std::vector<int> frameIndexIdle;
	std::vector<int> frameIndexRun;
	std::vector<int> frameIndexAttack1;
	std::vector<int> frameIndexAttack2;
	std::vector<int> frameIndexAttackZone;
	std::vector<int> frameIndexDie;

	// Lilian TEST

private:
	SpellsManager* _spellsManager;

	sf::Texture playerTexture;
	sf::Clock clock;
	sf::IntRect rectSprite;

	sf::Vector2i _mousePos;
	sf::Vector2f _playerCenter;
	sf::Vector2f _worldPosition;
	sf::Vector2f _aimDir;
	float angleDegrees;

	float endurancePlayer = 100;

	//Player attack basic
	sf::RectangleShape _basicAttack;
	bool _isAttacking = false;
	int _activeFrame = 10;
	int _frame = 0;
	int _cooldownBA = 0;
	void ResetBasicAttackCooldown() { _cooldownBA = 30;  }

	//rectangle pour endurance + vie
	sf::RectangleShape enduranceBar;
	sf::RectangleShape enduranceBarBack;
	sf::RectangleShape lifeBar;

	//cercle pour ulti + spell
	sf::CircleShape playerUltiUI;
	sf::CircleShape playerFirstSpell;
	sf::CircleShape playerSecondSpell;
	sf::CircleShape playerThirdSpell;

	sf::CircleShape playerUITab[4];

	int playerHP;
	sf::Vector2f _moveDirection;
	int playerSpeed = 20;
	float _modifierSpeed = 1;
	sf::Clock endurance;
};