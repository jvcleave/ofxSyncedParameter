#pragma once

#include "ofMain.h"
#include "ofxImGui.h"
#include "ofxSyncedParameter.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
    ofxImGui gui;
    
    ofxSyncedParameter<float> floatParam;
    void onFloatParamChanged(float& value);
    void onColorParamChanged(ofFloatColor& value);
    
    ofxSyncedParameter<int> intParam;
    ofxSyncedParameter<bool> boolParam;
    
    ImVec4 backgroundColor;
    ofxSyncedParameter<ofFloatColor> colorParam;


};
