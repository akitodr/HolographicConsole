#include "SpaceScreen.h"

void SpaceScreen::init() {
	for (int i = 0; i < 1000; i++) {
		stars.push_back(new Star());
	}
}

void SpaceScreen::update(float secs) {
	for (int i = 0; i < stars.size(); i++) {
		stars[i]->update(ofGetLastFrameTime());
	}
}

void SpaceScreen::draw() {
	ofBackground(0);
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	for (int i = 0; i < stars.size(); i++) {
		stars[i]->draw();
	}
	ofPopMatrix();
}