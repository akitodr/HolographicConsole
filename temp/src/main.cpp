#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main() {
    ofGLFWWindowSettings settings;
    settings.width = 800;
    settings.height = 600;
	settings.title = "Ship";
    settings.setPosition(ofVec2f(10, 50));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> shipWindow = ofCreateWindow(settings);
    
    settings.width = 800;
    settings.height = 600;
	settings.title = "Space";
    settings.setPosition(ofVec2f(650, 50));
    settings.resizable = true;
    
    // uncomment next line to share main's OpenGL resources
    settings.shareContextWith = shipWindow;
    shared_ptr<ofAppBaseWindow> spaceWindow = ofCreateWindow(settings);
    spaceWindow->setVerticalSync(false);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp->setupSpaceScreen();
    ofAddListener(spaceWindow->events().draw, mainApp.get(), &ofApp::drawSpaceScreen);
    
    ofRunApp(shipWindow, mainApp);
    ofRunMainLoop();
}


