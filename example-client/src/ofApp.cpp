#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetLogLevel("ofxNetwork", OF_LOG_SILENT);

    hasReceivedXML = false;
    xmlContent = "";
    didConnect = tcpClient.setup("127.0.0.1", 11999);
    gui = NULL;
}

//--------------------------------------------------------------
void ofApp::update()
{

    if(didConnect)
    {
        if(!hasReceivedXML)
        {
            if(tcpClient.send("getXML"))
            {
                
                //if data has been sent lets update our text
                string str = tcpClient.receive();
                if( str.length() > 0 )
                {
                    xmlContent = str;
                    ofBuffer xmlBuffer(xmlContent);
                    xml.loadFromBuffer(xmlBuffer);
                    parameterGroup = *xmlParmUtils.createGuiParameterGroup(xml);
                    gui = new ofxPanel(parameterGroup);
                    hasReceivedXML = true;
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

//--------------------------------------------------------------
void ofApp::draw()
{
    stringstream info;
    info << "didConnect: " << didConnect << endl;
    info << "xmlContent: " << endl;
    info << xmlContent << endl;

    if (parameterGroup)
    {
        //ofLogVerbose() << "parameterGroup->size(): " << parameterGroup.size();
        string output = parameterGroup.toString();
        info << output << endl;
        for(size_t i=0; i<parameterGroup.size(); i++)
        {
            //ofAbstractParameter* param = &parameterGroup[i];
            
            //string paramName = parameterGroup[i].toString();
            
            //info << paramName << endl;
        }
    }
    
    ofDrawBitmapStringHighlight(info.str(), 20, 20);
    
    if(gui)
    {
        gui->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
