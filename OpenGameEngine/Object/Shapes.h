//
//  Shape.h
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-07.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#ifndef __OpenGLGame__Shape__
#define __OpenGLGame__Shape__

#include <stdio.h>
#include "GameDrawable.h"

namespace OGECore {
    class GameShape : public GameDrawable{
    public:
        enum ShapeType{
            TRIANGLE,
            SQUARE,
            CIRCLE
        };
        
    public:
        GameShape(ShapeType t):type(t),GameDrawable(){
            genVBO(1);genVAO(1);
            program = new ShaderProgram("standard3","res/simpletransform.vsh","res/singlecolor.fsh");
        };
        virtual ~GameShape(){};
        
        void setColour(Color nCol){
            if (program != NULL) {
                program->setColorPrimary(nCol);
            }
        }                
        
    protected:
        ShapeType type;
        
    public:
        static void instantiate(GameShape& obj,glm::vec3 position){
            GameDrawable::instantiate(obj, position);
        }
    };
    
    class ShapeTriangle : public GameShape {
        
    public:
        ShapeTriangle():GameShape(ShapeType::TRIANGLE){};
        ~ShapeTriangle();
        
        void init();
        void update(OGEEvents::GameEvent* evt);
        void render(OGEEvents::GameEvent* evt);
        void onDestroy();
    };
    
    class ShapeSquare: public GameShape{
    public:
        ShapeSquare():GameShape(ShapeType::SQUARE){};
        ~ShapeSquare();
        
        void init();
        void update(OGEEvents::GameEvent* evt);
        void render(OGEEvents::GameEvent* evt);
        void onDestroy();
    };
}

#endif /* defined(__OpenGLGame__Shape__) */
