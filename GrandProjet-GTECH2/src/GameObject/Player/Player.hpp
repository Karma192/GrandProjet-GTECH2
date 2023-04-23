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
#include "Animation.h"

class Player : public GameObject 
{
public:
	Player();
	virtual ~Player();

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

	sf::Clock cdBasicAttack;
	sf::RectangleShape hitboxTest;

	//Player draw
	sf::Vector2f moveSpeed;

	// Lilian TEST

	Animation animation;

	std::vector<int> frameIndexIdle;
	std::vector<int> frameIndexRun;
	std::vector<int> frameIndexAttack1;
	std::vector<int> frameIndexAttack2;
	std::vector<int> frameIndexAttackZone;
	std::vector<int> frameIndexDie;

	// Lilian TEST

	bool IsAttacking = false;

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
	float cd_Endurance = endurance.getElapsedTime().asSeconds();

	//Player attack basic
	bool _dashing = false;
	bool isActtk = true;
	bool asAttacked = false;

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
	int m_pv;
	int m_attack;
	int playerSpeed = 20;
	float _modifierSpeed = 1;
	sf::Clock endurance;
};