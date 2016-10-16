//
//  GameWindow.h
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-04.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#ifndef __OpenGLGame__GameWindow__
#define __OpenGLGame__GameWindow__
#define GLM_FORCE_RADIANS

#include <stdio.h>

#include "GameEvent.h"
#include "GameCamera.h"
#include "Core.h"
#include "GameInputManager.h"

namespace OGECore {
    class GameWindow: public OGEObject {
        GLFWwindow *window;
        
    public:
        GameWindow(const char* title,int width,int height);
        ~GameWindow();
        
        int execute();
        void update();
        void render();
        
        void setTitle(const char*);
        void setSize(int width,int height);        
        void setClearColour(Color color);
        
        const char* getTitle();
        void getSize(int *width, int *height);
        Color getClearColour();
        
        
    private:
        const char* title;
        int width, height;
        Color clearColour;
        OGEEvents::GameEvent renderEvent;
        OGEEvents::GameEvent updateEvent;
        GameCamera camera;
        OGEEvents::GameInputManager* gameInputManager;
        
        long double deltaTime, lastTime;
    };
}



#endif /* defined(__OpenGLGame__GameWindow__) */
