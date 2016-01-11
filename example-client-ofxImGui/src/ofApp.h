#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"
#include "ControlPanel.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    ofxTCPClient tcpClient;
    bool didConnect;
    bool useServer;
    bool didSetup;

    
    ofParameterGroup parameterGroup;
    ControlPanel controlPanel;
    
};
