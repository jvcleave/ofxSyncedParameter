#pragma once
#include "ofMain.h"

class ParameterXMLUtils
{
public:
    ofXml* serializer;

    ParameterXMLUtils()
    {
        serializer = new ofXml();
    }
    
    ofParameter<bool> createBoolean(ofXml& xml)
    {
        string childName = xml.getName();
        ofParameter<bool> item;
        item.set(childName, xml.getBoolValue());
        return item;
    }
    
    
    ofParameterGroup* createGuiToggleParameterGroup(ofXml& xml)
    {
        ofParameterGroup* parameterGroup = new ofParameterGroup();
        string elementName = xml.getName();
        xml.setAttribute("type", "group");
        parameterGroup->setName(elementName);
        int numElementChildren = xml.getNumChildren();
        for(int i=0; i<numElementChildren; i++)
        {
            
            xml.setToChild(i);
            ofParameter<bool> item = createBoolean(xml);
            parameterGroup->add(item);
            xml.setToParent();
            
        }
        return parameterGroup;
    }
    
    
    void createXMLFromParam(ofAbstractParameter& parameter, ofXml& xml)
    {
        
        string parameterName = xml.getName();
        if(parameter.type()==typeid(ofParameter<int>).name())
        {
            xml.setAttribute("type", "int");
            int min = parameter.cast<int>().getMin();
            int max = parameter.cast<int>().getMax();
            xml.setAttribute("min", ofToString(min));
            xml.setAttribute("max", ofToString(max));
            return;
        }
        
        if(parameter.type()==typeid(ofParameter<float>).name())
        {
            
            xml.setAttribute("type", "float");
            float min = parameter.cast<float>().getMin();
            float max = parameter.cast<float>().getMax();
            //need this pre OF 0.9.1
            //https://github.com/openframeworks/openFrameworks/commit/ab527fa5d24348d28f58570b9ca3e8fa1a152ab5
            xml.setAttribute("min", ofToString(min));
            xml.setAttribute("max", ofToString(max));
            return;
        }
        
        if(parameter.type()==typeid(ofParameter<bool>).name())
        {
            xml.setAttribute("type", "bool");
            return;
        }
        
        if(parameter.type()==typeid(ofParameter<string>).name())
        {
            xml.setAttribute("type", "string");
            return;
        }
        
    }
    
    
    ofAbstractParameter* createGuiParameter(ofXml& xml)
    {
        string childName = xml.getName();
        string nodeType = xml.getAttribute("type");
        if (nodeType == "bool")
        {
            ofParameter<bool>* boolItem = new ofParameter<bool>();
            boolItem->set(childName, xml.getBoolValue());
            return (ofAbstractParameter*) boolItem;
        }
        if (nodeType == "int")
        {
            ofParameter<int>* intItem = new  ofParameter<int>();
            string min = xml.getAttribute("min");
            string max = xml.getAttribute("max");
            intItem->set(childName, xml.getIntValue(), ofToInt(min), ofToInt(max));
            return (ofAbstractParameter*) intItem;
        }
        
        if (nodeType == "float")
        {
            ofParameter<float>* floatItem = new  ofParameter<float>();
            string min = xml.getAttribute("min");
            string max = xml.getAttribute("max");
            floatItem->set(childName, xml.getFloatValue(), ofToFloat(min), ofToFloat(max));
            return (ofAbstractParameter*) floatItem;
        }
        return NULL;
    }
    
    
    ofParameterGroup* createGuiParameterGroup(ofXml& xml)
    {
        ofParameterGroup* parameterGroup = new ofParameterGroup();
        string elementName = xml.getName();
        parameterGroup->setName(elementName);
        int numElementChildren = xml.getNumChildren();
        for(int j=0; j<numElementChildren; j++)
        {
            
            xml.setToChild(j);
            parameterGroup->add(*createGuiParameter(xml));
            xml.setToParent();
            
        }
        return parameterGroup;
    }
    
    
    void saveXML(ofParameterGroup& parameters, string filePath)
    {
        serializer->serialize(parameters);
        
        ofXml xml(*serializer);
        ofLogVerbose(__func__) << "xml toString: " << xml.toString();
        
        int numRootChildren =  xml.getNumChildren();
        for(int i=0; i<numRootChildren; i++)
        {
            xml.setToChild(i);
            int numElementChildren = xml.getNumChildren();
            if (numElementChildren>0)
            {
                
                ofParameterGroup* parameterGroupPtr = createGuiToggleParameterGroup(xml);
                for(int j=0; j<numElementChildren; j++)
                {
                    xml.setToChild(j);
                    ofParameterGroup parameterGroup = *parameterGroupPtr;
                    createXMLFromParam(parameterGroup[xml.getName()], xml);
                    xml.setToParent();
                }
                
            }else 
            {
                createXMLFromParam(parameters[xml.getName()], xml);
            }
            
            xml.setToParent();
        }
        
        ofLogVerbose(__func__) << "xml processed: " << xml.toString();
        
        
        xml.save(filePath);
        
    }
};
