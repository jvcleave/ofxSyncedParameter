#include "ofApp.h"


void ofApp::onColorParamChanged(ofFloatColor& value)
{
    ofLogVerbose() << "onColorParamChanged: " << value;
}

void ofApp::onFloatParamChanged(float& value)
{
    ofLogVerbose() << "onFloatParamChanged: " << value;
}
//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    gui.setup();
    floatParam.set("floatParam", 0.0f, 0.0f, 1000.f);
    floatParam.addListener(this, &ofApp::onFloatParamChanged);
    floatParam.startUpdating();
    
    intParam.set("intParam", 100, 0, 2000);
    intParam.startUpdating();
    
    boolParam.set("do Random background Color", false);
    boolParam.startUpdating();
    
    colorParam.set("Background Color", ofColor::white);
    colorParam.addListener(this, &ofApp::onColorParamChanged);
    colorParam.startUpdating();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(boolParam)
    {
        colorParam.value = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetBackgroundColor(colorParam.value);
    gui.begin();
    
    ImGui::SliderFloat(floatParam.getName().c_str(),
                       &floatParam.value,
                       floatParam.getMin(),
                       floatParam.getMax());
    
    ImGui::SliderInt(intParam.getName().c_str(),
                       &intParam.value,
                       intParam.getMin(),
                       intParam.getMax());
    
    ImGui::Checkbox(boolParam.getName().c_str(), &boolParam.value);
    
    ImGui::ColorEdit3(colorParam.getName().c_str(), (float*)&colorParam.value);

    
    gui.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

