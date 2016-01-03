#pragma once
#include "ofMain.h"


template<typename T>
class SyncedParameter
{
public:
    ofParameter<T> parameter;
    T value;
    string name;
    bool hasAddedUpdateListener;
    SyncedParameter()
    {
        T temp;
        value = temp;
        parameter.set(name, value);
        name = "UNDEFINED";
        hasAddedUpdateListener = false;
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