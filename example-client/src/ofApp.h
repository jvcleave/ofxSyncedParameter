#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"
#include "ParameterXMLUtils.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    ofxTCPClient tcpClient;
    bool didConnect;
    string xmlContent;
    ofXml xml;
    bool hasReceivedXML;
    ParameterXMLUtils xmlParmUtils;
    
    ofParameterGroup parameterGroup;
    
    ofxPanel* gui;
};
