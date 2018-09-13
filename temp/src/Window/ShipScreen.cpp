#include "ShipScreen.h"

void ShipScreen::draw() {
	w = ofGetWidth() / 67.0f;
	h = ofGetHeight() / 11.0f;

    ofBackground(0);

	if (ofGetKeyPressed('x')) {
		for (int i = 0; i < 67; i++) {
			for (int j = 0; j < 11; j++) {
				ofDrawLine(i * w, 0, i * w, ofGetHeight());
				ofDrawLine(0, j * h, ofGetWidth(), j * h);
			}
		}
	}
}
