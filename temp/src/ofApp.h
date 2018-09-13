#pragma once

#include "ofMain.h"
#include "window/ShipScreen.h"
#include "window/SpaceScreen.h"


class ofApp : public ofBaseApp{
private:
	Spaceship spaceship;
	ShipScreen grid;
	SpaceScreen space;

public:
    void setup();
    void setupSpaceScreen();
    void update();
    void draw();
    void drawSpaceScreen(ofEventArgs& args);
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg); 
};


