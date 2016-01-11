#pragma once
#include "ofMain.h"
#include "ofxImGui.h"
#include "SyncedParameter.h"

#pragma GCC diagnostic ignored "-Wformat-security"

class ControlPanel
{
public:
    
    ofxImGui gui;
    ofParameterGroup parameterGroup;
    vector<void*> syncedParameters;
    string xmlContent;
    ControlPanel()
    {

    };
    
    void setup(ofParameterGroup* group)
    {
        
        parameterGroup = *group;
        for(size_t i=0; i<parameterGroup.size(); i++)
        {
            ofAbstractParameter* param = &parameterGroup[i];
            
            string paramString = param->type();
            
            if(param->type() == typeid(float)
            
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
