#include "ofApp.h"


void ofApp::onCurrentFrameUpdate(int& value)
{
    //ofLogVerbose() << "ofApp::oncurrentFrameUpdate: " << value;
}
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetVerticalSync(false);
    doWriteXML = false;
    timeElapsed.set("timeElapsed", 0.0f);
    timeElapsed.startUpdating();
    parametersAll.add(timeElapsed);

    //you can use your own ofParameter callbacks
    currentFrame.set("currentFrame", 0);
    currentFrame.addListener(this, &ofApp::onCurrentFrameUpdate);
    currentFrame.startUpdating();
  
    
    parametersAll.add(currentFrame);

    
    //you can use your exisiting ofParameters
    ofParameter<float> existingParameter;
    existingParameter.set("timeElapsedClone", 0.0f);
    timeElapsedClone.setFromExisting(existingParameter, true);
    
    parametersAll.add(existingParameter);

    //SyncedParameterCollection is good for a group, e.g. dropdown list content
    vector<int> ints;
    for(size_t i=0; i<5; i++)
    {
        ints.push_back(i);
    }
    intCollection.addItems(ints);
    
    
    vector<string> strings = {"Orange", "Pineapple", "Strawberry", "Watermelon"};
    for(size_t i=0; i<strings.size(); i++)
    {
        ofxSyncedParameter<string> param;
        param.set(strings[i], strings[i]);
        parametersAll.add(param);
        //option to add individual SyncedParameters
        stringCollection.push_back(param);
    }
    
    for(size_t i=0; i<5; i++)
    {
        ofxSyncedParameter<bool> param;
        param.set("bool_"+ofToString(i), true);
        parametersAll.add(param);
        boolCollection.push_back(param);
    }
    boolCollection.parameterGroup.setName("myBools");
    
    //use ofxOSCParameterSync
    //synchronizer.setup(boolCollection.getParameterGroup(),6667, "localhost", 6666);
    
    //group access
    parametersAll.add(boolCollection.getParameterGroup());
    
    //save everything to XML
    writeXML();
    
    xmlServer.setup(ofToDataPath("parameters.xml"));
    xmlServer.start();
                    
}

void ofApp:: writeXML()
{
    xmlUtils.saveXML(parametersAll, ofToDataPath("parameters.xml"));

}
//--------------------------------------------------------------
void ofApp::update(){

    timeElapsed.value = ofGetElapsedTimef();
    timeElapsedClone.value = ofGetElapsedTimef();
    
    currentFrame.value = ofGetFrameNum();
    
    for(size_t i=0; i<intCollection.collection.size(); i++)
    {
        intCollection.collection[i].value = ofRandom(10, 100);
    }
    
    for(size_t i=0; i<stringCollection.collection.size(); i++)
    {
        string existingString = stringCollection.collection[i].value;
        random_shuffle(existingString.begin(), existingString.end());
        stringCollection.collection[i].value = existingString;
    }
    
    for(size_t i=0; i<boolCollection.collection.size(); i++)
    {
        boolCollection.collection[i].value = (ofGetFrameNum()%2 == 0);
    }
    
    //synchronizer.update();
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    if(doWriteXML)
    {
        writeXML();
        doWriteXML = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    stringstream info;
    for(size_t i=0; i<parametersAll.size(); i++)
    {
        info << parametersAll[i].getName() << " : " << parametersAll[i] << endl;
    }
    ofDrawBitmapStringHighlight(info.str(), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key == 'w')
    {
        doWriteXML = true;
    }
}
