#pragma once

#include "ofMain.h"
#include "ofxSyncedParameter.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    
    ofxSyncedParameter<float> timeElapsed;
    void onTimeElapsedChanged(float& value);
};
