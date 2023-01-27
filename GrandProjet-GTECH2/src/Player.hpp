#pragma once 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <vector>

#define PLAYER_TEXTURE "ressources/sprites/player/idle.png"
#define PLAYER_IDLE {sf::IntRect(0, 0, 54, 52), sf::IntRect(69, 0, 54, 52),sf::IntRect(130, 0, 54, 52), sf::IntRect(195, 0, 54, 52) }


class Player {
public:
	Player();
	virtual ~Player();

	void PlayerLoop();
	void PlayerRender(sf::RenderWindow* window);

	//Player HUD 

	void playerEndurance();
	void playerRegenEndurance();
	void playerUI();

	void ControllerInput();

	void ControllerMove();

	void MovePlayer();

	//rectangle pour endurance + vie
	sf::RectangleShape enduranceBar;
	sf::RectangleShape enduranceBarBack;
	sf::RectangleShape lifeBar;

	//cercle pour ulti + spell
	sf::CircleShape playerUltiUI;
	sf::CircleShape playerFirstSpell;
	sf::CircleShape playerSecondSpell;
	sf::CircleShape playerThirdSpell;

	//test
	sf::RectangleShape cube;
	sf::Vector2f moveSpeed;

	int frame = 0;

	void setPv(int pv) { m_pv = pv; }
	int getPv() const { return m_pv; }
	void setAttack(int attack) { m_attack = attack; }
	int getAttack() const { return m_attack; }

	///Exemples d'applications des fonctions des PV/Attaque au dessus (Pandouille) ///

	/*player.setPv(100);
	player.setAttack(20);

	int pv = player.getPv();
	int attack = player.getAttack();
  
	void takeDamage(int damage)
	{
		m_pv -= damage;
		if (m_pv < 0) m_pv = 0;
	}
	*/

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

protected:
	float endurancePlayer = 100;
	float cd_Endurance = endurance.getElapsedTime().asSeconds();

private:

	sf::Clock clock;
	int m_pv;
	int m_attack;
	int playerSpeed = 120;
	sf::Clock endurance;
};