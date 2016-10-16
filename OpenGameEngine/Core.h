//
//  Core.h
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-07.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#ifndef OpenGLGame_Core_h
#define OpenGLGame_Core_h
#define GLM_FORCE_RADIANS
#define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <OpenGL/gl3.h>

namespace OGECore{
    class OGEObject{};
    
    struct Color {
        int r, g, b;
        int alpha;
        Color():r(0),g(0),b(0),alpha(0){};
        Color(int r,int g, int b):r(r),g(g),b(b),alpha(255){};
        Color(int r,int g, int b,int alpha):r(r),g(g),b(b),alpha(alpha){};
        ~Color(){};
        
        bool operator==(const Color other){
            return r == other.r && g == other.g && b == other.b && alpha == other.alpha;
        }
        bool operator!=(const Color other){
            return r != other.r || g != other.g || b != other.b || alpha != other.alpha;
        }
    };
    
    struct Colorf:Color{
        float r,g,b;
        float alpha;
        Colorf():r(0),g(0),b(0),alpha(0){};
        Colorf(Color color):r(color.r),g(color.g),b(color.b),alpha(color.alpha){};
        Colorf(float r,float g, float b):r(r),g(g),b(b),alpha(1.f){};
        Colorf(float r,float g, float b,float alpha):r(r),g(g),b(b),alpha(alpha){};
        ~Colorf(){};
        
        Color intVal(){return Color(r * 255,g * 255, b * 255, alpha * 255);};
        
        bool operator==(const Color other){
            return r == other.r && g == other.g && b == other.b && alpha == other.alpha;
        }
        bool operator!=(const Color other){
            return r != other.r || g != other.g || b != other.b || alpha != other.alpha;
        }
    };
    
    
#define OGEColorBlack (Color(0,0,0))
#define OGEColorWhite (Color(255,255,255))
#define OGEColorRed (Color(255, 0, 0))
#define OGEColorBlue (Color(0,0,255))
#define OGEColorGreen (Color(0,255,0))
#define OGEColorClear (Color(0,0,0,0))
}

#endif
