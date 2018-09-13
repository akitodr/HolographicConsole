#include "LaserShot.h"

LaserShot::LaserShot(const ofVec3f& position) : position(position) {}

void LaserShot::init() {
	ofBackground(0);
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	ofEnableLighting();
	ofSetGlobalAmbientColor(ofColor(0, 0, 0));
	ofDisableArbTex();
	ofSetSmoothLighting(true);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	for (int i = 1; i < 8; i++) {
		glDisable(GL_LIGHT0 + i);
	}

	//dir.setDiffuseColor(ofColor(255.0f, 255.0f, 255.0f));
	//dir.setSpecularColor(ofColor(255.0f, 255.0f, 255.0f));
	//dir.setDirectional();
	//dir_rot = ofVec3f(0, 0, 45);
	//setLightOri(dir, dir_rot);
	

	//material.setShininess(120);

	//material.setSpecularColor(ofColor(255, 255, 255, 255));
	//material.setEmissiveColor(ofColor(50, 50, 50, 255));
	//material.setDiffuseColor(ofColor(255, 255, 255, 255));
	//material.setAmbientColor(ofColor(255, 255, 255, 255));

	model.loadModel("lasershot.obj", 20);
	model.setScale(1, 1, 1);
	model.setPosition(position.x, position.y, position.z);



	//dir.setPosition(model.getPosition());

	increment = 5.f;
	sound.load("piupiu.mp3");
	sound.play();
}

void LaserShot::update(float secs) {
	lightPos.set(position);
	position.z -= increment * secs;
	model.setPosition(position.x, position.y, position.z);
	GLfloat p[4] = { position.x, position.y, position.z, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, p);
	cout << position.z << endl;
}

void LaserShot::draw() {
	//ofEnableLighting();
	//dir.enable();
	//material.begin();
	glPushMatrix();
	//texture.bind();
	glEnable(GL_LIGHTING);
	model.drawFaces();
	glDisable(GL_LIGHTING);
	//texture.unbind();
	glPopMatrix();
	//material.end();
	ofSetColor(255, 255, 255, 255);
}

bool LaserShot::isAlive() {
	return true;
}

ofVec3f LaserShot::getPosition() const {
	return position;
}

ofRectangle LaserShot::bounds() {
	return ofRectangle();
}

void LaserShot::setLightOri(ofLight &light, ofVec3f rot)
{
	ofVec3f xax(1, 0, 0);
	ofVec3f yax(0, 1, 0);
	ofVec3f zax(0, 0, 1);
	ofQuaternion q;
	q.makeRotate(rot.x, xax, rot.y, yax, rot.z, zax);
	light.setOrientation(q);
}