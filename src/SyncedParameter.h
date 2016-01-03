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
        parameter.set(name, value);
        name = "UNDEFINED";
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
    
    void set(string name_, T value_, bool doUpdate = true)
    {
        if(!name_.empty())
        {
            name = name_;
        }
        
        value = value_;
        parameter.set(name, value);
        if(doUpdate)
        {
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
        if(value != parameter)
        {
            parameter = value;
            didChange = true;
        }
        return didChange;
    }
};