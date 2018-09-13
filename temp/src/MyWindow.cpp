#include "MyWindow.h"


void MyWindow::init() {
	spaceship.init();
}

void MyWindow::update(float secs) {
	spaceship.update(secs);
}

void MyWindow::draw() {
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	spaceship.draw();
}
