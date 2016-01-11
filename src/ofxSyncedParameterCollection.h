#pragma once
#include "ofxSyncedParameter.h"

template<typename T>
class ofxSyncedParameterCollection
{
public:
    map<int, ofxSyncedParameter<T>> collection;
    ofParameterGroup parameterGroup;
    bool hasAddedUpdateListener;
    int numItems;
    ofxSyncedParameterCollection()
    {
        numItems = 0;
        hasAddedUpdateListener = false;
        
    };
    
    
    void push_back(ofxSyncedParameter<T>& syncedParameter)
    {
        
        collection[numItems] = syncedParameter;
        numItems++;
        ofLogVerbose() << "numItems: " << numItems;
        parameterGroup.add(syncedParameter);
        if(!hasAddedUpdateListener)
        {
            ofAddListener(ofEvents().update, this, &ofxSyncedParameterCollection::onUpdate);
            hasAddedUpdateListener = true;
        }
        collection[numItems].startUpdating();
    }
    
    ofParameterGroup& getParameterGroup()
    {
        return parameterGroup;
    }
    
    //TODO: test
    void addItems(ofParameterGroup& parameterGroup_)
    {
        for(size_t i=0; i<parameterGroup_.size(); i++)
        {
            ofxSyncedParameter<T> syncedParameter;
            syncedParameter.set(parameterGroup[i], false);
            push_back(&syncedParameter);
        }
    }
    void addItems(vector<T>& items)
    {
        for(size_t i = 0; i<items.size(); i++)
        {
            ofxSyncedParameter<T> syncedParameter;
            syncedParameter.set(ofToString(collection.size()),
                                items[i]);
            push_back(syncedParameter);
        }
    }
    
    void onUpdate(ofEventArgs& event)
    {
        for(size_t i = 0; i<collection.size(); i++)
        {
            bool didChange = collection[i].update();
            if(didChange)
            {
                //ofLogVerbose() << collection[i].name << " CHANGED TO " << collection[i].value;
            }
        }
        
    }
};
