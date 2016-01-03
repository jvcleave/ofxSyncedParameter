#pragma once
#include "ofMain.h"


template<typename T>
class SyncedParameter
{
public:
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
        STRING
    };
    PARAM_TYPE type;
    ofParameter<T> parameter;
    T value;
    string name;
    string typeName;
    bool hasAddedUpdateListener;
    SyncedParameter()
    {
        typeName="";
        name = "UNDEFINED";
        hasAddedUpdateListener = false;
        T temp;
        value = temp;
        parameter.set(name, value);
        
        string t = parameter.type();
        if(t==typeid(ofParameter<int32_t>).name()) { type = INT32_T; typeName = "int32_t";}
        if(t==typeid(ofParameter<uint32_t>).name()) { type = UINT32_T; typeName = "uint32_t";}
        if(t==typeid(ofParameter<int64_t>).name()) { type = INT64_T; typeName = "int64_t";}
        if(t==typeid(ofParameter<uint64_t>).name()) { type = UINT64_T; typeName = "uint64_t";}
        if(t==typeid(ofParameter<int8_t>).name()) { type = INT8_T; typeName = "int8_t";}
        if(t==typeid(ofParameter<uint8_t>).name()) { type = UINT8_T; typeName = "uint8_t";}
        if(t==typeid(ofParameter<int16_t>).name()) { type = INT16_T; typeName = "int16_t";}
        if(t==typeid(ofParameter<uint16_t>).name()) { type = UINT16_T; typeName = "uint16_t";}
        if(t==typeid(ofParameter<float>).name()) { type = FLOAT; typeName = "float";}
        if(t==typeid(ofParameter<bool>).name()) { type = BOOL; typeName = "bool";}
        if(t==typeid(ofParameter<ofVec2f>).name()) { type = OFVEC2F; typeName = "ofVec2f";}
        if(t==typeid(ofParameter<ofVec3f>).name()) { type = OFVEC3F; typeName = "ofVec3f";}
        if(t==typeid(ofParameter<ofVec4f>).name()) { type = OFVEC4F; typeName = "ofVec4f";}
        if(t==typeid(ofParameter<ofColor>).name()) { type = OFCOLOR; typeName = "ofColor";}
        if(t==typeid(ofParameter<ofShortColor>).name()) { type = OFSHORTCOLOR; typeName = "ofShortColor";}
        if(t==typeid(ofParameter<ofFloatColor>).name()) { type = OFFLOATCOLOR; typeName = "ofFloatColor";}
        if(t==typeid(ofParameter<string>).name()) { type = STRING; typeName = "string";}
    }
    
    template <typename ArgumentsType, class ListenerClass>
    void set(string name_,
             T value_,
             ListenerClass  * listener,
             void (ListenerClass::*listenerMethod)(ArgumentsType&),
             bool doUpdate = false)
    {
        set(name_, value_, doUpdate);
        parameter.addListener(listener, listenerMethod);
    }
    
    void set(string name_, T value_, bool doUpdate = false)
    {
        if(!name_.empty())
        {
            name = name_;
        }
        
        value = value_;
        parameter.set(name, value);
        if(doUpdate)
        {
            startUpdating();
        }
        
    }
    
    void startUpdating()
    {
        if(!hasAddedUpdateListener)
        {
            hasAddedUpdateListener = true;
            ofAddListener(ofEvents().update, this, &SyncedParameter::onUpdate);
        }
    }
    
    void onUpdate(ofEventArgs& event)
    {
        update();
    }
    
    bool update()
    {
        bool didChange =false;
        //TODO: better way than to serialize?
        if(ofToString(value) != parameter.toString())
        {
            parameter = value;
            didChange = true;
        }
        return didChange;
    }
};