#pragma once
#include "ofMain.h"
#include "ofxImGui.h"
#include "ofxSyncedParameter.h"
#include "ParameterXMLUtils.h"
#include "ParameterTypeUtils.h"

#pragma GCC diagnostic ignored "-Wformat-security"

class ControlPanel
{
public:
    
    ofxImGui gui;
    string xmlString;
    ofXml xml;
    ParameterXMLUtils xmlParmUtils;
    
    map<int, ofxSyncedParameter<float>> floatParams;
    map<int, ofxSyncedParameter<int>> intParams;
    map<int, ofxSyncedParameter<bool>> boolParams;

    ControlPanel()
    {
    };
    
    void setup(string xmlString_)
    {
        xmlString = xmlString_;
        
        ofBuffer xmlBuffer(xmlString);
        xml.loadFromBuffer(xmlBuffer);
        
        string elementName = xml.getName();
        int numElementChildren = xml.getNumChildren();
        for(int j=0; j<numElementChildren; j++)
        {
            
            xml.setToChild(j);
            ofAbstractParameter* param = xmlParmUtils.createGuiParameter(xml);
            ProbeResult probeResult = ParameterTypeUtils::probeType(param);
            switch(probeResult.type)
            {
                case FLOAT:
                {
                    ParameterTypeUtils::collectParams(param, floatParams);
                    break;
                }
                case INT16_T:
                case INT32_T:
                case INT64_T:
                case INT8_T:
                {
                    ParameterTypeUtils::collectParams(param, intParams);
                    break;
                }
                case BOOL:
                {
                    ParameterTypeUtils::collectParams(param, boolParams);
                    break;
                }
            }
            xml.setToParent();
            
        }
    }
    
    void draw()
    {
        
        gui.begin();
        for(size_t i=0; i<floatParams.size(); i++)
        {
            ImGui::SliderFloat(floatParams[i].getName().c_str(),
                               &floatParams[i].value,
                               floatParams[i].getMin(),
                               floatParams[i].getMax());
            
        }
        for(size_t i=0; i<intParams.size(); i++)
        {
            ImGui::SliderInt(intParams[i].getName().c_str(),
                             &intParams[i].value,
                             intParams[i].getMin(),
                             intParams[i].getMax());
            
        }
        for(size_t i=0; i<boolParams.size(); i++)
        {
            ImGui::RadioButton(boolParams[i].getName().c_str(),
                               &boolParams[i].value);
            
        }
        gui.end();
 
    }
};
