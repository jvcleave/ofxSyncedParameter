#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    parameters.setName("parameters");
    for(size_t i=0; i<5; i++)
    {
        ofParameter<bool> param;
        param.set("bool_"+ofToString(i), true);
        parameters.add(param);
    }

	// by now needs to pass the gui parameter groups since the panel internally creates it's own group
	sync.setup(parameters,6666,"localhost",6667);
	ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
	sync.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	for(int i=0;i<parameters.size();i++)
    {
        stringstream info;
        info << parameters[i].getName();
        info << ":" << parameters[i];
        ofDrawBitmapStringHighlight(info.str(), 20, 20*(i+1));
	}
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
