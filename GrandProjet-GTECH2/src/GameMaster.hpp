#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include "GameObject.hpp"
#include "CollisionManager.h"

using namespace sf;

struct GameData {
	int indexScene = 0;
	RenderWindow* window = nullptr;
	Event* event = nullptr;
	int indexMap = 0;
};

enum {
	MENU = 0,
	LOBBY = 1,
	INGAME = 2,
};

class GameMaster 
{
protected:
	static GameMaster* instance;
	static GameData data;
	static std::vector<GameObject*> _listGameObject;
	CollisionManager* _cm;

public:
	GameMaster();
	GameMaster(GameMaster& other) = delete;

	void operator=(const GameMaster&) = delete;

	static GameMaster* GetInstance();

	// Fonction pour r�cuperer la liste d'objets
	static std::vector<GameObject*> GetListGameObject();
	// Fonction pour ajouter un objet � la liste
	static void AddGameObject(GameObject*);
	// Fonction pour recuperer les donnees du jeu
	static GameData GetGameData();
	// Fonction pour changer de scene
	void SetActiveScene(int);
	// Fonction pour setup du Game Master
	void SetWindow(RenderWindow*, Event*);
	// Fonction pour d�truire les objets � d�truire
	void Purge();
	// Fonction pour r�cup�rer le CollisionManager
	void SetCollisionManager(CollisionManager*);
};