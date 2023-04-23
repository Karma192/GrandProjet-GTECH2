#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

struct GameData {
	int indexScene = 0;
	sf::RenderWindow* window = nullptr;
	sf::Event* event = nullptr;
	int indexMap = 0;
};

enum Scene {
	MENU = 0,
	LOBBY = 1,
	INGAME = 2,
};

class GameObject;

class GameMaster 
{
protected:
	static GameMaster* instance;
	static GameData data;
	std::vector<GameObject*> _listGameObject;

public:
	GameMaster();
	GameMaster(GameMaster& other) = delete;

	void operator=(const GameMaster&) = delete;

	static GameMaster* GetInstance();

	// Fonction pour recuperer la liste d'objets
	std::vector<GameObject*> GetListGameObject();
	// Fonction pour ajouter un objet a la liste
	void AddGameObject(GameObject*);
	// Fonction pour initialiser les objets du jeu
	void InitObject();
	// Fonction pour recuperer les donnees du jeu
	static GameData GetGameData();
	// Fonction pour recuperer la fenetre
	static sf::RenderWindow* Window();
	// Fonction pour recuperer l'event
	static sf::Event* Event();
	// Fonction pour Draw les objets
	static void Draw(sf::Drawable &drawable);
	// Fonction pour changer de scene
	void SetActiveScene(int);
	// Fonction pour setup du Game Master
	void SetWindow(sf::RenderWindow*, sf::Event*);
	// Fonction pour detruire les objets a detruir   e
	void Purge();
};