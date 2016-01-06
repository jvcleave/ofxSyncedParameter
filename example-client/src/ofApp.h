#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    ofxTCPClient tcpClient;
    bool didConnect;
    string xmlContent;
    bool hasReceivedXML;
};
