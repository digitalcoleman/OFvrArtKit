#include "ofApp.h"

GLfloat lightOnePosition[] = {40.0, 40, 100.0, 0.0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};

//--------------------------------------------------------------
void ofApp::setup(){
    // Give us a starting point for the camera
    camera.setNearClip(0.01f);
    camera.setPosition( 0, 4, 10 );
    camera.setMovementMaxSpeed( 0.1f );
    
    topView.setPosition(0, 100, 0);
    topView.setOrientation(ofVec3f(-90, 0, 0));
    
    testDot.setRadius(5);
    
    ofSetVerticalSync(true);
    
    //some model / light stuff
    ofEnableDepthTest();
    glShadeModel (GL_SMOOTH);
    
    /* initialize lighting */
    glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, lightOneColor);
    glEnable (GL_LIGHT0);
    glLightfv (GL_LIGHT1, GL_POSITION, lightTwoPosition);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, lightTwoColor);
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);
    glColorMaterial (GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable (GL_COLOR_MATERIAL);
    
    currMod = 1;
    //load the model - the 3ds and the texture file need to be in the same folder
    
    ofxAssimpModelLoader modelTemp;
    modelTemp.loadModel("NewSquirrel.3ds", 20);
    models.push_back(modelTemp);
    
    //you can create as many rotations as you want
    //choose which axis you want it to effect
    //you can update these rotations later on
//    models[currMod].setRotation(0, 90, 1, 0, 0);
//    squirrelModel.setRotation(1, 270, 0, 0, 1);
//    models[currMod].setScale(0.05, 0.05, 0.05);
//    squirrelModel.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //convert mouse to viewspace for hit test
    ofVec2f mouse(mouseX, mouseY);
    ofVec3f cur = topView.worldToScreen(testDot.getPosition());
    float distance = cur.distance(mouse);
    if(distance < 3){
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient( ofColor(40,40,40), ofColor(0,0,0), OF_GRADIENT_CIRCULAR);
    
    ofEnableDepthTest();
    
    topView.begin();
    
    // draw a grid on the floor
    ofSetColor( ofColor(60) );
    ofPushMatrix();
    ofRotate(90, 0, 0, -1);
    ofDrawGridPlane( 10 );
    ofPopMatrix();
    
    ofSetColor(ofColor::red);
    testDot.draw();
    
    ofSetColor( ofColor::white );
    for( auto model: models) {
        model.drawFaces();
    }
    
    topView.end();
    
    ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 'f' )
    {
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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