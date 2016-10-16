//
//  Texture.h
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-07.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#ifndef __OpenGLGame__Texture__
#define __OpenGLGame__Texture__

#include <stdio.h>
#include "Core.h"
#include "ShaderProgram.h"
#include "GameComponent.h"

namespace OGECore {
    class Texture: public GameComponent{
        
    public:
        enum Type{
            COLOUR,
            IMAGE
        };        
        
        Color color;
        
    public:
        Texture();
        ~Texture();
        
        void setTexture(char* filename);
        void apply(ShaderProgram& program);
        void init();
        void update();
        
    protected:
        Type type;
        GLuint uvBuffer;
        GLuint textureRef;
        GLuint textureID;
  
    };
}

#endif /* defined(__OpenGLGame__Texture__) */
