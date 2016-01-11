#pragma once

#include "ofMain.h"
#include "ofxSyncedParameter.h"
#include "ofxSyncedParameterCollection.h"
#include "ofxOscParameterSync.h"
#include "ParameterXMLUtils.h"
#include "XMLServer.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
    
    ofxSyncedParameter<float> timeElapsed;
    ofxSyncedParameter<int> currentFrame;
    ofxSyncedParameterCollection<int> intCollection;
    ofxSyncedParameterCollection<string> stringCollection;
    ofxSyncedParameterCollection<bool> boolCollection;
    
    ofxSyncedParameter<float> timeElapsedClone;
    
    vector<ofxSyncedParameter<string>> stringParams;
    
    void onCurrentFrameUpdate(int& value);
    
    ofxOscParameterSync synchronizer;
    ParameterXMLUtils xmlUtils;
    XMLServer xmlServer;
    ofParameterGroup parametersAll;
    
    bool doWriteXML;
    void writeXML();
    
};
