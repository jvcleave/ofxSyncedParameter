#pragma once

#include "ofMain.h"
#include "ofxSyncedParameter.h"
#include "ofxSimpleGuiToo.h"

//https://github.com/memo/ofxMSAInteractiveObject
//https://github.com/memo/ofxSimpleGuiToo

class testApp : public ofBaseApp {
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
    
    ofxSyncedParameter<bool>myBool1Animate;
    ofxSyncedParameter<bool>myBool2;
    ofxSyncedParameter<bool>myBool3;
    ofxSyncedParameter<bool>myBool4;
    ofxSyncedParameter<bool>myBool5;
    ofxSyncedParameter<bool>myBool6;
    ofxSyncedParameter<bool>myBool7;
    ofxSyncedParameter<bool>myBool8;
    ofxSyncedParameter<bool>myBool9;
    
    ofxSyncedParameter<int>myInt1;
    ofxSyncedParameter<int>myInt2;
    ofxSyncedParameter<int>myInt3;
    ofxSyncedParameter<int>myInt4;
    ofxSyncedParameter<int>myInt5;
    ofxSyncedParameter<int>myInt6;
    ofxSyncedParameter<int>myInt7;
    ofxSyncedParameter<int>myInt8;
    ofxSyncedParameter<int>myInt9;
    
    ofxSyncedParameter<int>box1;
    ofxSyncedParameter<int>box2;
    
    ofxSyncedParameter<float>myFloat1;
    ofxSyncedParameter<float>myFloat2;
    ofxSyncedParameter<float>myFloat3;
    ofxSyncedParameter<float>myFloat4;
    ofxSyncedParameter<float>myFloat5;
    ofxSyncedParameter<float>myFloat6;
    ofxSyncedParameter<float>myFloat7;
    ofxSyncedParameter<float>myFloat8;
    ofxSyncedParameter<float>myFloat9;
    ofxSyncedParameter<ofFloatColor> aColor;
    ofxSyncedParameter<bool> randomizeButton;

};

