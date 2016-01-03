#pragma once
#include "SyncedParameter.h"

template<typename T>
class SyncedParameterCollection
{
public:
    vector<SyncedParameter<T>> collection;
    ofParameterGroup parameterGroup;
    bool hasAddedUpdateListener;
    SyncedParameterCollection()
    {
        hasAddedUpdateListener = false;
    };
    
    
    void push_back(SyncedParameter<T>& syncedParameter)
    {
        collection.push_back(syncedParameter);
        parameterGroup.add(syncedParameter.parameter);
        if(!hasAddedUpdateListener)
        {
            ofAddListener(ofEvents().update, this, &SyncedParameterCollection::onUpdate);
            hasAddedUpdateListener = true;
        }
    }
    
    ofParameterGroup& getParameterGroup()
    {
        return parameterGroup;
    }
    void addItems(vector<T>& items)
    {
        for(size_t i = 0; i<items.size(); i++)
        {
            SyncedParameter<T> syncedParameter;
            syncedParameter.set(ofToString(collection.size()),
                                items[i],
                                false);
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
