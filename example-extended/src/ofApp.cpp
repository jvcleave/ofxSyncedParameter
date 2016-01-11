#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    syncedParameter.set("test", 1000.f);
    syncedParameter.startUpdating();
    
    existing.set("existing", 1000.f);
    fromExisting.setFromExisting(existing);
    fromExisting.startUpdating();
}

//--------------------------------------------------------------
void ofApp::update(){
    syncedParameter.value = ofGetElapsedTimef();
    fromExisting.value = syncedParameter*2;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofLogVerbose() << syncedParameter;
    ofLogVerbose() << fromExisting;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
