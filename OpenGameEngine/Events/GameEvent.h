//
//  OGEEvent.h
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-09.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#ifndef __OpenGLGame__GameEvent__
#define __OpenGLGame__GameEvent__

#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <functional>
#include <thread>
#include "Core.h"

// Common OGEEvent types
#define OGEWindowRenderEvent_NAME ("OGE_RENDER_EVT")
#define OGEEventType_Render ("OGE_EVT_TYPE_RENDER")
#define OGEWindowUpdateEvent_NAME ("OGE_UPDATE_EVT")
#define OGEEventType_Update ("OGE_EVT_TYPE_UPDATE")

namespace OGEEvents{
    
    class GameEvent : OGECore::OGEObject{
        
        
    public:
        // the game event delegate type
        typedef void(*OGEEventDelegate)(GameEvent*);
      
        GameEvent(const char * type,OGECore::OGEObject* sender):type(type),sender(sender),OGECore::OGEObject(){};
        ~GameEvent(){};
      
        // Call the game event asynchronously BUGGED
        void call(){
          std::thread callThread(&GameEvent::call_thread,this);
        };
      
        // call the game event synchronously
        void callWait(){
            call_thread();
        }
      
        OGEObject* sender;
        const char* type;
        const char* name;
      
        // Add parameters to the event
        void setParamObject(const char* key, OGEObject* param){paramsObj[key] = param;};
        void setParamFloat(const char* key, float param){paramsFloat[key] = param;};
        void setParamInt(const char* key, int param){paramsInt[key] = param;};
        void setParamString(const char* key, std::string param){paramsStr[key] = param;};
        void setParamChar(const char* key, char param){paramsChar[key] = param;};
        void setParamMat4(const char* key, glm::mat4 param){paramsMat4[key] = param;};
        void setParamLong(const char* key, long param){paramsLong[key] = param;};
        void setParamLongDouble(const char* key, long double param){paramsLongDouble[key] = param;};
        void addDelegate(OGEEventDelegate delegate){delegates.push_back(delegate);};
      
        // Retrieve paramaters from the event
        OGEObject* getParamObject(const char* key){return paramsObj[key];};
        float getParamFloat(const char* key){return paramsFloat[key];};
        int getParamInt(const char* key){return paramsInt[key];};
        std::string getParamString(const char* key){return paramsStr[key];};
        char getParamChar(const char* key){return paramsChar[key];};
        glm::mat4 getParamMat4(const char* key){return paramsMat4[key];};
        long getParamLong(const char* key){return paramsLong[key];};
        long double getParamLongDouble(const char* key){return paramsLongDouble[key];};
      
    private:
      // Send a message to all of the delegates
      void call_thread(){
        for (int i = 0; i < delegates.size(); i++) {
          delegates[i](this);
        }
      };
      
    private:
        std::vector<OGEEventDelegate> delegates;
      
        // Parameters for each type
        std::map<const char*, OGEObject*> paramsObj;
        std::map<const char*, float> paramsFloat;
        std::map<const char*, int> paramsInt;
        std::map<const char*, std::string> paramsStr;
        std::map<const char*, char> paramsChar;
        std::map<const char*, glm::mat4> paramsMat4;
        std::map<const char*, long> paramsLong;
        std::map<const char*, long double>paramsLongDouble;
    };
    
    class GameEventManager: OGECore::OGEObject{
    public:
        typedef void(*OGEEventDelegate)(GameEvent*);
        // Add an event to the Event Manager
        static void registerEvent(GameEvent& evt){
            events.push_back(&evt);
        };
      
        // Find a game event by its name
        static GameEvent* eventByName(const char* name){
            for (int i = 0; i < events.size(); i++) {
                if (events[i]->name == name) {
                    return events[i];
                }
            }
            return NULL;
        }
      
        // Register a delegate by the event name
        static void registerDelegateByName(const char* name,OGEEventDelegate del){
            for (int i = 0; i < events.size(); i++) {
                if (events[i]->name == name) {
                    events[i]->addDelegate(del);
                }
            }
        };
      
        // Register a delegate by the event type
        static void registerDelegateByType(const char* type,OGEEventDelegate del){
            for (int i = 0; i < events.size(); i++) {
                if (events[i]->type == type) {
                    events[i]->addDelegate(del);
                }
            }
        };
        
        static std::vector<GameEvent*> events;
    };
}


#endif /* defined(__OpenGLGame__GameEvent__) */
