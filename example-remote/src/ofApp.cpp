#include "ofApp.h"

vector<int> ints;

void ofApp::onCurrentFrameUpdate(int& value)
{
    //ofLogVerbose() << "ofApp::oncurrentFrameUpdate: " << value;
}
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetVerticalSync(false);
    timeElapsed.set("timeElapsed", 10.f);
    

    //currentFrame.set("currentFrame", 0);
    //currentFrame.parameter.addListener(this, &ofApp::onCurrentFrameUpdate);

    currentFrame.set("currentFrame", 0, this, &ofApp::onCurrentFrameUpdate);

    for(size_t i=1; i<5; i++)
    {
        ints.push_back(i);
    }
    
    intCollection.addItems(ints);
    
    vector<string> strings = {"Orange", "Pineapple", "Strawberry", "Watermelon"};

    for(size_t i=0; i<strings.size(); i++)
    {
        SyncedParameter<string> stringParam;
        //TODO: why have to pass false? (causes crash)
        stringParam.set(strings[i], strings[i], false);
        
        stringCollection.push_back(stringParam);
        
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

    timeElapsed.value = ofGetElapsedTimef();
    currentFrame.value = ofGetFrameNum();
    
    for(size_t i=0; i<intCollection.collection.size(); i++)
    {
        intCollection.collection[i].value = ofRandom(10, 100);
    }
    
    for(size_t i=0; i<stringCollection.collection.size(); i++)
    {
        stringCollection.collection[i].value = ofToString(ofGetElapsedTimef());
    }
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
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
