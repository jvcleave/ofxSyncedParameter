#pragma once
#include "ofMain.h"


template<typename T>
class SyncedParameter
{
public:
    ofParameter<T> parameter;
    T value;
    string name;
    SyncedParameter()
    {
        T temp;
        value = temp;
        name = "UNDEFINED";
    }
    
    void onChange(T& paramValue)
    {
        ofLogVerbose() << name << " changed " << paramValue << endl;
    }
    
    void set(string name_, T value_, bool doUpdateEvent=true)
    {
        if(!name_.empty())
        {
           name = name_;
        }
        
        value = value_;
        parameter.set(name, value);
        parameter.addListener(this, &SyncedParameter::onChange);
        if(doUpdateEvent)
        {
            ofAddListener(ofEvents().update, this, &SyncedParameter::onUpdate);
        }
        
    }
    
    void onUpdate(ofEventArgs& event)
    {
        update();
    }
    
    void update()
    {
        if(value != parameter)
        {
            parameter = value;
        }
    }
};