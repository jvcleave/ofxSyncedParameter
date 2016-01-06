#pragma once

#include "ofMain.h"
#include "SyncedParameter.h"
#include "SyncedParameterCollection.h"
#include "ofxOscParameterSync.h"
#include "ParameterXMLUtils.h"
#include "XMLServer.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    
    
    SyncedParameter<float> timeElapsed;
    SyncedParameter<int> currentFrame;
    SyncedParameterCollection<int> intCollection;
    SyncedParameterCollection<string> stringCollection;
    SyncedParameterCollection<bool> boolCollection;
    
    SyncedParameter<float> timeElapsedClone;
    
    vector<SyncedParameter<string>> stringParams;
    
    void onCurrentFrameUpdate(int& value);
    
    ofxOscParameterSync synchronizer;
    ParameterXMLUtils xmlUtils;
    XMLServer xmlServer;
    ofParameterGroup parametersAll;
    
    bool doWriteXML;
    void writeXML();
    
};
