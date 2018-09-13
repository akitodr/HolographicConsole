#include "Star.h"

Star::Star()
{
	position.x = ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2);
	position.y = ofRandom(-ofGetHeight() / 2, ofGetHeight() / 2);
	position.z = ofRandom(ofGetWidth());
	speed = 50.0f;
}

void Star::update(float secs)
{
    sPosition.x = ofMap(position.x / position.z, 0, 1, 0, ofGetWidth());
    sPosition.y = ofMap(position.y / position.z, 0, 1, 0, ofGetHeight());
    
    position.z -= speed * secs;
    
	if (ofGetKeyPressed(OF_KEY_UP)) {
		position.y += speed * secs;
	}
	else if (ofGetKeyPressed(OF_KEY_DOWN)) {
		position.y -= speed * secs;
    }
    if (ofGetKeyPressed(OF_KEY_LEFT)) {
        position.x += speed * secs;
    } else if (ofGetKeyPressed(OF_KEY_RIGHT)) {
        position.x -= speed * secs;
    }

	if (position.z > ofGetWidth() || position.z < 1) {
		position.z = ofRandom(ofGetWidth());
		position.x = ofRandom(-ofGetWidth(), ofGetWidth());
		position.y = ofRandom(-ofGetHeight(), ofGetHeight());
	}
    checkBounds();
}

void Star::draw() {
	float r = ofMap(position.z, 0, ofGetWidth(), 5, 0);
	ofSetColor(255, 255, 255);
	ofDrawCircle(sPosition.x, sPosition.y, r, r);
}

void Star::checkBounds() {
    if(sPosition.x < -ofGetWidth() || sPosition.x > ofGetWidth() ||
       sPosition.y < -ofGetHeight() || sPosition.y > ofGetHeight()) {
        position.z = ofRandom(ofGetWidth());
        position.x = ofRandom(-ofGetWidth(), ofGetWidth());
        position.y = ofRandom(-ofGetHeight(), ofGetHeight());
    }
}

void Star::setPosition(const ofVec3f& pos) {
	position = pos;
}

void Star::setPosition(float x, float y, float z) {
	position = ofVec3f(x, y, z);
}

ofVec3f Star::getPosition() {
	return position;
}
