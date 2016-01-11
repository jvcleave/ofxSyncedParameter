#pragma once
#include "ofMain.h"
#include "ofxImGui.h"
#include "ofxSyncedParameter.h"
#include "ParameterXMLUtils.h"

#pragma GCC diagnostic ignored "-Wformat-security"

class ControlPanel
{
public:
    
    ofxImGui gui;
    ofParameterGroup parameterGroup;
    string xmlContent;
    ofXml xml;
    
    ParameterXMLUtils xmlParmUtils;
    ControlPanel()
    {
    };
    
    void setup(string input)
    {
        ofBuffer xmlBuffer(input);
        xml.loadFromBuffer(xmlBuffer);
        
        string elementName = xml.getName();
        int numElementChildren = xml.getNumChildren();
        for(int j=0; j<numElementChildren; j++)
        {
            
            xml.setToChild(j);
            ofAbstractParameter* param = xmlParmUtils.createGuiParameter(xml);
            //get type
            
            ofxSyncedParameter syncedParameter;
            
            xml.setToParent();
            
        }
        
        parameterGroup = *xmlParmUtils.createGuiParameterGroup(xml);
        for(size_t i=0; i<parameterGroup.size(); i++)
        {
            ofAbstractParameter* param = &parameterGroup[i];
            
            string paramString = param->type();
            
            //ofxSyncedParameter.h
            ofLogVerbose() << paramString;
        }
    }
    
    void draw()
    {
        /*
        if(parameterGroup)
        {
            string output = parameterGroup->toString();
            

            gui.begin();
            ImGui::Text(xmlContent.c_str());
            ImGui::Text(output.c_str());
            
            gui.end();
        }
         */
 
    }
};
