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
//        value = temp;
    };
    
    string type() const
    {
        return typeid(ofParameter<T>).name();
    }
    void setFromExisting(ofParameter<T>& existingParameter, bool doUpdate = false )
    {
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
        string currentValue = ofParameter<T>::toString();
        if(ofToString(value) != currentValue)
        {
            this->set(this->getName(), value);
            didChange = true;
        }
#if 0
        
        if(!isBooleanType)
        {
            //TODO: better way than to serialize?
            string currentValue = ofParameter<T>::toString();
            if(ofToString(value) != currentValue)
            {
                this->set(this->getName(), value);
                didChange = true;
            }
        }else
        {
            ofAbstractParameter* a = (ofAbstractParameter*)this;
            bool currentValue = a->cast<bool>();
            
            if(value != currentValue)
            {
                //*a = currentValue;
                this->set(this->getName(), true);
                didChange = true;
            }
        }
#endif
        return didChange;
    }
};
