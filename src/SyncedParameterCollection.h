#pragma once
#include "SyncedParameter.h"

template<typename T>
class SyncedParameterCollection
{
public:
    vector<SyncedParameter<T>> collection;
    bool hasAddedListener;
    SyncedParameterCollection()
    {
        hasAddedListener = false;
    };
    
    void onChange(T& paramValue)
    {
        //ofLogVerbose() << paramValue;
    }
    
    void push_back(SyncedParameter<T>& syncedParam)
    {
        collection.push_back(syncedParam);
        if(!hasAddedListener)
        {
            ofAddListener(ofEvents().update, this, &SyncedParameterCollection::onUpdate);
            hasAddedListener = true;
        }
    }
    
    void addItems(vector<T>& items)
    {
        for(size_t i = 0; i<items.size(); i++)
        {
            SyncedParameter<T> syncedParam;
            syncedParam.set(ofToString(collection.size()),
                            items[i],
                            this,
                            &SyncedParameterCollection::onChange);
            push_back(syncedParam);
        }
    }
    
    void onUpdate(ofEventArgs& event)
    {
        for(size_t i = 0; i<collection.size(); i++)
        {
            bool didChange = collection[i].update();
            if(didChange)
            {
                ofLogVerbose() << collection[i].name << " CHANGED TO " << collection[i].value;
            }
        }
        
    }
};
