#pragma once
#include "ofMain.h"
#include "ofxSyncedParameter.h"


enum PARAM_TYPE
{
    INT32_T,
    UINT32_T,
    INT64_T,
    UINT64_T,
    INT8_T,
    UINT8_T,
    INT16_T,
    UINT16_T,
    FLOAT,
    DOUBLE,
    BOOL,
    OFVEC2F,
    OFVEC3F,
    OFVEC4F,
    OFCOLOR,
    OFSHORTCOLOR,
    OFFLOATCOLOR,
    STRING,
    GROUP,
    UNKNOWN
};

struct ProbeResult
{
    PARAM_TYPE type = UNKNOWN;
    string typeName="unknown";
};

class ParameterTypeUtils
{
public:
    
   static ProbeResult probeType(ofAbstractParameter* parameter)
    {

        ProbeResult result;
        
        string t = parameter->type();
        if(t==typeid(ofParameter<int32_t>).name()) { result.type = INT32_T; result.typeName = "int32_t";}
        if(t==typeid(ofParameter<uint32_t>).name()) { result.type = UINT32_T; result.typeName = "uint32_t";}
        if(t==typeid(ofParameter<int64_t>).name()) { result.type = INT64_T; result.typeName = "int64_t";}
        if(t==typeid(ofParameter<uint64_t>).name()) { result.type = UINT64_T; result.typeName = "uint64_t";}
        if(t==typeid(ofParameter<int8_t>).name()) { result.type = INT8_T; result.typeName = "int8_t";}
        if(t==typeid(ofParameter<uint8_t>).name()) { result.type = UINT8_T; result.typeName = "uint8_t";}
        if(t==typeid(ofParameter<int16_t>).name()) { result.type = INT16_T; result.typeName = "int16_t";}
        if(t==typeid(ofParameter<uint16_t>).name()) { result.type = UINT16_T; result.typeName = "uint16_t";}
        if(t==typeid(ofParameter<float>).name()) { result.type = FLOAT; result.typeName = "float";}
        if(t==typeid(ofParameter<bool>).name()) { result.type = BOOL; result.typeName = "bool";}
        if(t==typeid(ofParameter<ofVec2f>).name()) { result.type = OFVEC2F; result.typeName = "ofVec2f";}
        if(t==typeid(ofParameter<ofVec3f>).name()) { result.type = OFVEC3F; result.typeName = "ofVec3f";}
        if(t==typeid(ofParameter<ofVec4f>).name()) { result.type = OFVEC4F; result.typeName = "ofVec4f";}
        if(t==typeid(ofParameter<ofColor>).name()) { result.type = OFCOLOR; result.typeName = "ofColor";}
        if(t==typeid(ofParameter<ofShortColor>).name()) { result.type = OFSHORTCOLOR; result.typeName = "ofShortColor";}
        if(t==typeid(ofParameter<ofFloatColor>).name()) { result.type = OFFLOATCOLOR; result.typeName = "ofFloatColor";}
        if(t==typeid(ofParameter<string>).name()) { result.type = STRING; result.typeName = "string";}
        if(t==typeid(ofParameterGroup).name()) { result.type = GROUP; result.typeName = "group";}
        
        if(result.type == UNKNOWN)
        {
            ofLogVerbose() << t << " UNKNOWN";
        }

        return result;
    }

    
    static void collectParams(ofAbstractParameter* param, map<int, ofxSyncedParameter<float>>& syncedParams)
    {
        int index = syncedParams.size();
        
        ofParameter<float> temp = param->cast<float>();
        temp.setName(param->getName());
        if(temp == temp.getMin() && temp == temp.getMax())
        {
            temp.setMin(temp-10);
            temp.setMax(temp+10);
        }
        syncedParams[index].setFromExisting(temp, true);
    }

    static void collectParams(ofAbstractParameter* param, map<int, ofxSyncedParameter<int>>& syncedParams)
    {
        int index = syncedParams.size();
        
        ofParameter<int> temp = param->cast<int>();
        temp.setName(param->getName());
        syncedParams[index].setFromExisting(temp, true);
    }

    static void collectParams(ofAbstractParameter* param, map<int, ofxSyncedParameter<bool>>& syncedParams)
    {
        int index = syncedParams.size();
        
        ofParameter<bool> temp = param->cast<bool>();
        temp.setName(param->getName());
        syncedParams[index].setFromExisting(temp, true);
    }


};



