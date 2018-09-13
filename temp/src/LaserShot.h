#pragma once

#include "GameObject.h"
#include "ofxAssimpModelLoader\src\ofxAssimpModelLoader.h"

class LaserShot : public GameObject {
	private:
		ofxAssimpModelLoader model;
		ofTexture texture;
		ofLight dir;
		ofMaterial material;
		ofVec3f lightPos;
		ofVec3f position;
		ofSoundPlayer sound;
		float increment;

	public:
		LaserShot(const ofVec3f& position);
		void init();
		void update(float secs);
		void draw();
		bool isAlive();
		ofVec3f getPosition() const;
		ofRectangle bounds();
		void setLightOri(ofLight &light, ofVec3f rot);
};