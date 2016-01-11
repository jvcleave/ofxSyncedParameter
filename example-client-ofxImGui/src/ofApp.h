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
    bool hasReceivedXML;

    
    ofParameterGroup parameterGroup;
    ControlPanel controlPanel;
    
};
