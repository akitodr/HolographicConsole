#pragma once

#include "GameObject.h"

#define GAMEMANAGER GameManager::instance()

class GameManager {
private:
	vector<GameObject*> objects;
	vector<GameObject*> dead;
	GameManager();

public:
	static GameManager& instance();
	void clear();
	void add(GameObject* object);
	void orderByDistance();
	bool isOrdered();
	void update(float secs);
	void drawShipScreen(); 
	void drawSpaceScreen();
	~GameManager();
};