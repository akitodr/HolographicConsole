#pragma once
#include "ofMain.h"

class Star {
private:
	ofVec3f position;
    ofVec2f sPosition;
	float pz, speed;
    
public:
	Star();
	void update(float secs);
	void draw();
    void checkBounds();
	void setPosition(const ofVec3f& pos);
	void setPosition(float x, float y, float z);
	ofVec3f getPosition();
};
