#include "GameManager.h"

GameManager::GameManager() {}

void GameManager::clear() {
	for (GameObject* object : objects) {
		delete  object;
	}
	objects.clear();
}

void GameManager::add(GameObject* object) {
	object->init();
	objects.push_back(object);
}

void GameManager::orderByDistance() {
	for (int i = 0; i < objects.size() - 1; i++) {
		if (objects[i]->getPosition().z > objects[i + 1]->getPosition().z) {
			GameObject* aux = objects[i];
			objects[i] = objects[i + 1];
			objects[i + 1] = aux;
		}
	}
	if (!isOrdered()) 
		orderByDistance();
}

bool GameManager::isOrdered() {
	for (int i = 0; i < objects.size() - 1; i++) {
		if (objects[i]->getPosition().z > objects[i + 1]->getPosition().z) {
			return false;
		}
	}
	return true;
}

void GameManager::update(float secs) {
	std::vector<GameObject*> alive;
	std::vector<GameObject*> toDelete;

	std::swap(toDelete, dead);


	//Para cada objeto object em objects
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->update(secs);
		if (!objects[i]->isAlive()) {
			dead.push_back(objects[i]);
		}
		else {
			alive.push_back(objects[i]);
		}
	}

	/*for (int i = 0; i < objects.size() - 1; i++) {
		for (int j = i + 1; j < objects.size(); j++) {
			if (objects[i]->bounds().intersects(objects[j]->bounds())) {
				objects[i]->collidedWith(objects[j]);
				objects[j]->collidedWith(objects[i]);
			}
		}
	}*/

	for (GameObject* object : toDelete) {
		delete object;
	}

	std::swap(alive, objects);
	
	orderByDistance();
}

void GameManager::drawShipScreen() {
	for (GameObject* object : objects) {
		if(object->getPosition().z > ofGetWidth() / 2)
			object->draw();
	}
}

void GameManager::drawSpaceScreen() {
	for (GameObject* object : objects) {
		if (object->getPosition().z < ofGetWidth() / 2)
			object->draw();
	}
}

GameManager& GameManager::instance() {
	static GameManager manager;
	return manager;
}

GameManager::~GameManager() {
	clear();
}