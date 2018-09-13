#pragma once
#include "GameObject.h"
#include "MappedImage.h"
#include "LaserShot.h"

class Spaceship : public GameObject {
private:
	MappedImage image;
    ofVec3f position;
	LaserShot* shot;
	bool isClicked;
public:
	void init();
	void update(float secs);
	void draw();
	void checkBorders();
	bool isAlive();
	ofVec3f getPosition() const;
	ofBoxPrimitive bounds();
};
