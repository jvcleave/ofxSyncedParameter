#include "ofApp.h"


void ofApp::onParamUpdate(int& paramValue)
{
    ofLogVerbose() << "ofApp::onParamUpdate: " << paramValue;
}
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    timeElapsed.set("timeElapsed", 10.f);
    fps.setWithCallback("fps", 0, this, &ofApp::onParamUpdate);
    
    fps.parameter.addListener(this, &ofApp::onParamUpdate);

}

//--------------------------------------------------------------
void ofApp::update(){
    ofLogVerbose() << "update";
    timeElapsed.value = ofGetElapsedTimef();
    fps.value = ofGetFrameNum();
}

//--------------------------------------------------------------
void ofApp::draw(){

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
