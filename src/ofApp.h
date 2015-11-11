#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAssimpModelLoader.h"

#include "Math/MathUtils.h"
#include "Cameras/ofxWalkingFirstPersonCamera.h"

#define numModels 20

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxFirstPersonCamera	camera;
        ofCamera topView;
        ofSpherePrimitive testDot;
        //ofxAssimpModelLoader models[numModels];
        vector<ofxAssimpModelLoader> models;
    
    int currMod;
};
