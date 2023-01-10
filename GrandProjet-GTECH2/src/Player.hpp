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
	void PlayerTest(sf::RenderWindow* window);
	void PlayerRender(sf::RenderWindow* window);
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

private:
	sf::Clock clock;
	int m_pv;
	int m_attack;

};