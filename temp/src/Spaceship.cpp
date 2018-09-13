#include "Spaceship.h"
#include "GameManager.h"



void Spaceship::init() {
	image.init();
	position = ofVec3f(ofGetWidth() / 2, 0, ofGetWidth());
	isClicked = false;
}

void Spaceship::update(float secs) {
    float speed = 200.0f;

    if (ofGetKeyPressed(OF_KEY_LEFT)) {
        position.x -= speed * secs;
    }
    if (ofGetKeyPressed(OF_KEY_RIGHT)) {
        position.x += speed * secs;
    }
    if (ofGetKeyPressed(OF_KEY_UP)) {
        position.y -= speed * secs;
    }
    if (ofGetKeyPressed(OF_KEY_DOWN)) {
        position.y += speed * secs;
    }
	if (isClicked && !ofGetKeyPressed(OF_KEY_LEFT_SHIFT)) {
		isClicked = false;
	}
	if (ofGetKeyPressed(OF_KEY_LEFT_SHIFT) && !isClicked) {
		isClicked = true;
		GAMEMANAGER.add(new LaserShot(ofVec3f(position.x, position.y, position.z)));
	}
	checkBorders();
}

void Spaceship::draw() {
	ofPushMatrix();
	ofTranslate(position.x, position.y);
	image.getImageFromMatrix(position).draw(-100, -100, 200, 215);
	ofPopMatrix();
}

bool Spaceship::isAlive() {
	return true;
}

ofVec3f Spaceship::getPosition() const {
	return position;
}

ofBoxPrimitive Spaceship::bounds() {
	return ofBoxPrimitive();
}

void Spaceship::checkBorders() {
	if (position.x < 50) position.x = 50;
	if (position.x > ofGetWidth() - 50) position.x = ofGetWidth() -50;
	if (position.y < 50) position.y = 50;
	if (position.y > ofGetHeight() -50) position.y = ofGetHeight() -50;
}
