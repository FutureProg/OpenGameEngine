//
//  GameCamera.h
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-13.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#ifndef __OpenGLGame__GameCamera__
#define __OpenGLGame__GameCamera__

#include <stdio.h>
#include "GameObject.h"

namespace OGECore {
    class GameCamera : public GameObject{
    public:
        static GameCamera* main;
        
    public:
        GameCamera():GameObject(){};
        ~GameCamera(){};
        
        
        void init();
        void update(OGEEvents::GameEvent* evt);
        void onDestroy();
        
    private:
        glm::mat4 view;
        
    };
}
#endif /* defined(__OpenGLGame__GameCamera__) */
