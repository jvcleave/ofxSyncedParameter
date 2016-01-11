#include "ofApp.h"


#define STRINGIFY(x) #x

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetLogLevel("ofxNetwork", OF_LOG_SILENT);

    didSetup = false;
    useServer = false;
    if(useServer)
    {
        didConnect = tcpClient.setup("127.0.0.1", 11999);

    }
}

//--------------------------------------------------------------
void ofApp::update()
{

    if(useServer)
    {
        if(didConnect)
        {
            if(!didSetup)
            {
                if(tcpClient.send("getXML"))
                {
                    string xmlString = tcpClient.receive();
                    if( xmlString.length() > 0 )
                    {
                        controlPanel.setup(xmlString);
                        didSetup = true;
                    }
                }else
                {
                    
                    if(!tcpClient.isConnected())
                    {
                        didConnect = false;
                    }
                }
            }
            
        }
    }
    else
    {
        if(!didSetup)
        {
            string xmlString = STRINGIFY(
             <group>
             <timeElapsed max="3.40282e+38" min="-3.40282e+38" type="float">0</timeElapsed>
             <currentFrame max="2147483647" min="-2147483648" type="int">0</currentFrame>
             <timeElapsedClone max="3.40282e+38" min="-3.40282e+38" type="float">0</timeElapsedClone>
             <Orange type="string">Orange</Orange>
             <Pineapple type="string">Pineapple</Pineapple>
             <Strawberry type="string">Strawberry</Strawberry>
             <Watermelon type="string">Watermelon</Watermelon>
             <bool_0 type="bool">1</bool_0>
             <bool_1 type="bool">1</bool_1>
             <bool_2 type="bool">1</bool_2>
             <bool_3 type="bool">1</bool_3>
             <bool_4 type="bool">1</bool_4>
             <myBools type="group">
                <bool_0 type="bool">1</bool_0>
                <bool_1 type="bool">1</bool_1>
                <bool_2 type="bool">1</bool_2>
                <bool_3 type="bool">1</bool_3>
                <bool_4 type="bool">1</bool_4>
             </myBools>
             </group>
            );
            
            controlPanel.setup(xmlString);
            didSetup = true;
        }
       
        
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    controlPanel.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
