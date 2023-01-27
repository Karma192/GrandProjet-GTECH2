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

	//void takeDamage(int damage) { m_pv -= damage; if (m_pv < 0) m_pv = 0; }

	void ControllerInput();

	void ControllerMove();

	void MovePlayer();

	//cercle pour ulti + spell
	sf::CircleShape playerUltiUI;
	sf::CircleShape playerFirstSpell;
	sf::CircleShape playerSecondSpell;
	sf::CircleShape playerThirdSpell;

	//rectangle pour endurance + vie
	sf::RectangleShape enduranceBar;
	sf::RectangleShape enduranceBarBack;
	sf::RectangleShape lifeBar;
	void setAttack(int attack) { m_attack = attack; }
	int getAttack() const { return m_attack; }

	void setSpeed(int speed) { m_speed = speed; }
	int getSpeed() const { return m_speed; }

	//test
	sf::RectangleShape cube;
	sf::Vector2f moveSpeed;
	void setAttackSpeed(int attackspeed) { m_attackspeed = attackspeed; }
	int getAttackSpeed() const { return m_attackspeed; }

	void setGold(int gold) { m_gold = gold; }
	int getGold() const { return m_gold; }

	void setKeys(int keys) { m_keys = keys; }
	int getKeys() const { return m_keys; }

	void setLuck(int luck) { m_luck = luck; }
	int getLuck() const { return m_luck; }
	
	
	
	
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

private:
	sf::Clock clock;

	int m_pv;
	int m_attack;
	int m_speed;
	int m_attackspeed;
	int m_gold;
	int m_keys;
	int m_luck;
};