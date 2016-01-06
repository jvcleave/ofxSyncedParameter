#pragma once
#include "ofMain.h"
#include "ofxNetwork.h"


class XMLServer
{
    
public:
    
    bool isConnected;
    bool hasSent;
    ofxTCPServer tcpServer;
    ofBuffer xml;
    int connectTime;
    string ip;
    int port;
    
    XMLServer()
    {
        isConnected = false;
        hasSent = false;
        connectTime = 0;
        port = 11999;
    };
    
    void start()
    {
        ofAddListener(ofEvents().update, this, &XMLServer::onUpdate);
    }
    
    void stop()
    {
        ofRemoveListener(ofEvents().update, this, &XMLServer::onUpdate);
    }
    
    void setup(string filePath, int port_=11999)
    {
        port = port_;
        xml = ofBufferFromFile(filePath);
        tcpServer.setup(port);
    }
    
                      
                      
    void onUpdate(ofEventArgs& event)
    {
      update();
    }
                      
    void update()
    {
        
        for(int i = 0; i < tcpServer.getLastID(); i++)
        {
            
            if( tcpServer.isClientConnected(i) )
            {
                string input = tcpServer.receive(i);
                if(input == "getXML")
                {
                    tcpServer.send(i, xml.getText());
                }
            }
        }
    }
    
 
};
