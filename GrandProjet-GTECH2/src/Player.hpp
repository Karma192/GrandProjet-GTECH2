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

	void setSpeed(int speed) { m_speed = speed; }
	int getSpeed() const { return m_speed; }

	void setAttackSpeed(int attackspeed) { m_attackspeed = attackspeed; }
	int getAttackSpeed() const { return m_attackspeed; }

	void setGold(int gold) { m_gold = gold; }
	int getGold() const { return m_gold; }
	
	
	
	
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

private:
	sf::Clock clock;
	int m_pv;
	int m_attack;
	int m_speed;
	int m_attackspeed;
	int m_gold;
};