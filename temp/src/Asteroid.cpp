#include "Asteroid.h"

void Asteroid::init() {
	ofBackground(0);
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	ofSetGlobalAmbientColor(ofColor(0, 0, 0));
	ofDisableArbTex();
	ofSetSmoothLighting(true);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);


	dir.setDiffuseColor(ofColor(255.0f, 255.0f, 255.0f));
	dir.setSpecularColor(ofColor(255.0f, 0.0f, 0.0f));
	dir.setDirectional();
	dir_rot = ofVec3f(0, -115, 0);
	setLightOri(dir, dir_rot);

	material.setShininess(120);

	material.setSpecularColor(ofColor(255, 255, 255, 255));
	material.setEmissiveColor(ofColor(50, 50, 50, 255));
	material.setDiffuseColor(ofColor(255, 255, 255, 255));
	material.setAmbientColor(ofColor(255, 255, 255, 255));

	ofLoadImage(texture, "rock.jpg");

	model.loadModel("asteroid.obj", 20);
	model.setScale(0.5, 0.5, 0.5);
	model.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth());

	increment = 0.f;
}

void Asteroid::update(float secs) {
	increment += 4.f;
	model.setRotation(2, 45 + ofGetElapsedTimef() * 60, 1, 1, 1);
	model.setPosition(ofGetWidth() / 2, ofGetHeight() / 2, -(ofGetWidth() * 2) + increment);
	position.set(model.getPosition().x, model.getPosition().y, model.getPosition().z);
	cout << model.getPosition().z << endl;
}

void Asteroid::draw() {
	ofEnableLighting();
	dir.enable();
	material.begin();
	glPushMatrix();
	texture.bind();
	ofSetColor(255, 255, 255, 255);
	model.drawFaces();
	texture.unbind();
	glPopMatrix();
	ofDisableLighting();
	material.end();
}

bool Asteroid::isAlive() {
	return true;
}

ofBoxPrimitive Asteroid::bounds()
{
	return ofBoxPrimitive();
}

ofVec3f Asteroid::getPosition() const
{
	return position;
}

void Asteroid::setLightOri(ofLight &light, ofVec3f rot)
{
	ofVec3f xax(1, 0, 0);
	ofVec3f yax(0, 1, 0);
	ofVec3f zax(0, 0, 1);
	ofQuaternion q;
	q.makeRotate(rot.x, xax, rot.y, yax, rot.z, zax);
	light.setOrientation(q);
}
