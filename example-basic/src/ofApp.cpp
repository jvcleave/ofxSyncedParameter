#include "ofApp.h"


void ofApp::onTimeElapsedChanged(float& value)
{
    ofLogVerbose() << "onTimeElapsedChanged: " << value;
}
//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    //setup as you would with a regular ofParameter<float>
    timeElapsed.set("timeElapsed", 0.0f);
    
    /*
    ofxSyncedParameter uses an internal event listener 
    to check value changes on update and syncs the 
    ofParameter value if changed
    */
    timeElapsed.startUpdating();
    
    //you can use callbacks as you would as well
    timeElapsed.addListener(this, &ofApp::onTimeElapsedChanged);
}

//--------------------------------------------------------------
void ofApp::update()
{
    //You can change the value of the parameter like this
    
    timeElapsed.value = ofGetElapsedTimef();
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    stringstream info;
    info << timeElapsed.value << endl;
    
    ofDrawBitmapStringHighlight(info.str(), 20, 20);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
