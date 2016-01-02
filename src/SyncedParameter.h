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
    
    void setup(string name_, T value_)
    {
        if(!name_.empty())
        {
            name = name_;
        }
        
        value = value_;
        parameter.set(name, value);
    }
    
    void onChange(T& paramValue)
    {
        ofLogVerbose() << name << " changed " << paramValue;
    }
    
    template <typename ArgumentsType, class ListenerClass>
    void setWithCallback(string name_,
                         T value_,
                         ListenerClass  * listener,
                         void (ListenerClass::*listenerMethod)(ArgumentsType&))
    {
        setup(name_, value_);
        addChangeListener(listener, listenerMethod);
    }
    
    

    template <typename ArgumentsType, class ListenerClass>
    void addChangeListener(ListenerClass  * listener, void (ListenerClass::*listenerMethod)(ArgumentsType&))
    {
        parameter.addListener(listener, listenerMethod);
    }
    
    void set(string name_, T value_, bool doUpdateEvent=true)
    {
        setup(name_, value_);
        addChangeListener(this, &SyncedParameter::onChange);
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