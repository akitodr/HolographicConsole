#pragma once

#include "GameObject.h"
#include "ofxAssimpModelLoader\src\ofxAssimpModelLoader.h"

class Asteroid : public GameObject {
private:
	ofxAssimpModelLoader model;
	ofTexture texture;
	ofLight dir;
	ofMaterial material;
	ofVec3f dir_rot;
	ofVec3f position;
	float increment;
public:
	// Inherited via GameObject
	virtual void init() override;
	virtual void update(float secs) override;
	virtual void draw() override;
	virtual bool isAlive() override;
	virtual ofBoxPrimitive bounds() override;
	virtual ofVec3f getPosition() const override;
	//let's see what happen
	void setLightOri(ofLight &light, ofVec3f rot);
};