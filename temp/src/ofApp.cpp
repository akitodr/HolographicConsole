#include "ofApp.h"
#include "GameManager.h"
#include "Asteroid.h"

//--------------------------------------------------------------
void ofApp::setup() {
	GAMEMANAGER.add(&spaceship);
}

void ofApp::setupSpaceScreen() {
	GAMEMANAGER.add(new Asteroid());
	space.init();
}

//--------------------------------------------------------------
void ofApp::update(){
	space.update(ofGetLastFrameTime());
    GAMEMANAGER.update(ofGetLastFrameTime());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
	grid.draw();
	GAMEMANAGER.drawShipScreen();
}

void ofApp::drawSpaceScreen(ofEventArgs& args) {
	space.draw();
	GAMEMANAGER.drawSpaceScreen();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}


