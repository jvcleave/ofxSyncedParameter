#pragma once
#include "ofMain.h"



template<typename T>
class SyncedParameter
{
public:
   
    ofParameter<T> parameter;
    T value;
    string name;
    bool isUpdating;
    
    SyncedParameter()
    {
        name = "UNDEFINED";
        isUpdating = false;
        T temp;
        value = temp;
        parameter.set(name, value);
        string t = parameter.type();

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
    
    void set(ofParameter<T>& existingParameter, bool doUpdate = false )
    {
        if(!existingParameter.getName().empty())
        {
            name = existingParameter.getName();
        }
        value = existingParameter;
        parameter.makeReferenceTo(existingParameter);
        if(doUpdate)
        {
            startUpdating();
        }
        
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
        if(!isUpdating)
        {
            isUpdating = true;
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