//
//  GameComponent.h
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-09-11.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#ifndef __OpenGLGame__GameComponent__
#define __OpenGLGame__GameComponent__

#include <stdio.h>
#include "Core.h"
#include "GameEvent.h"

namespace OGECore {
    class GameComponent : public OGEObject {
        
        
    public:
        GameComponent(){};
        ~GameComponent(){};
        
        virtual void init() = 0;
        virtual void update(OGEEvents::GameEvent) = 0;
        
        bool enabled;
        
        char* getName(){return name;};
        
    protected:
        char* name;
        
    };
}

#endif /* defined(__OpenGLGame__GameComponent__) */
