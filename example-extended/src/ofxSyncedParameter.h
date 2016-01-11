#pragma once
#include "ofMain.h"

template<typename T>
class ofxSyncedParameter: public ofParameter<T>
{
public:
    
    T value;
    ofxSyncedParameter()
    {
        T temp;
        value = temp;
    };
    
    void setFromExisting(ofParameter<T>& existingParameter, bool doUpdate = false )
    {
        if(!existingParameter.getName().empty())
        {
            this->setName(existingParameter.getName());
        }
        value = existingParameter;
        this->makeReferenceTo(existingParameter);
        if(doUpdate)
        {
            startUpdating();
        }
        
    }
    
    void startUpdating()
    {
        ofAddListener(ofEvents().update, this, &ofxSyncedParameter::onUpdate);

    }
    void onUpdate(ofEventArgs& event)
    {
        update();
    }
    
    bool update()
    {
        bool didChange =false;
        //TODO: better way than to serialize?
        if(ofToString(value) != this->toString())
        {
            this->set(this->getName(), value);
            didChange = true;
        }
        return didChange;
    }
};
