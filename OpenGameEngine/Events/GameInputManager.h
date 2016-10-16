//
//  GameInputManager.h
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-20.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#ifndef __OpenGLGame__GameInputManager__
#define __OpenGLGame__GameInputManager__

#include <stdio.h>
#include "Core.h"
#include "GameEvent.h"
#include <map>

namespace OGEEvents {
  
    class GameInputManager {
        
        typedef int GLFWKey;
    private:
        enum{
            Pressing,
            JustReleased,
            Released,
            NotPressing
        };
    public:
        GameInputManager(GLFWwindow &window);
        ~GameInputManager(){};
      
        // Updates the state of each key
        void update(OGEEvents::GameEvent* evt){
            for (std::map<int,int>::iterator it = keystates.begin(); it != keystates.end(); it++) {
                if (keystates[it->first] == JustReleased) {
                    keystates[it->first] = Released;
                }
                else if (keystates[it->first] == Released){
                    keystates[it->first] = NotPressing;
                }
            }
        };
      
        // List of keystates, mapped by the GLFWKey
        static std::map<int,int> keystates;
      
        // Callback function that sets the state of each key upon pressing
        static void key_callback(GLFWwindow* window,int key, int scancode, int action, int mods){
            if (keystates.find(key) != keystates.end()) {
                if (keystates[key] == Pressing && action == GLFW_RELEASE) {
                    keystates[key] = JustReleased;
                    return;
                }
            }
            switch (action) {
                case GLFW_PRESS:
                    GameInputManager::keystates[key] = Pressing;
                    break;
                case GLFW_RELEASE:
                    GameInputManager::keystates[key] = NotPressing;
                default:
                    break;
            }
        };
      
        // Check the key state of each key
        static bool getKeyUp(GLFWKey key){
            return keystates.find(key) != keystates.end() && keystates[key] == NotPressing;
        };
        static bool getKeyPressed(GLFWKey key){
            return keystates.find(key) != keystates.end() && keystates[key] == Pressing;
        };
        static bool getKeyReleased(GLFWKey key){
            return keystates.find(key) != keystates.end() && (keystates[key] == JustReleased || keystates[key] == Released);
        };
    };
}


#endif /* defined(__OpenGLGame__GameInputManager__) */
