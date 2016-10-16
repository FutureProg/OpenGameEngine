//
//  GameDrawable.h
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-05.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#ifndef __OpenGLGame__GameDrawable__
#define __OpenGLGame__GameDrawable__

#include <stdio.h>
#include "GameObject.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include "GameEvent.h"

namespace OGECore {
    class GameDrawable:public GameObject{
        
    protected:
        GLuint* VBO;
        GLuint* VAO;
        
        GLfloat* _vertices;
        glm::vec3 position;
        glm::vec3 scale;
        glm::vec3 rotation;
        glm::mat4 model;
        ShaderProgram* program;
      
        Texture *texture;
    public:
        GameDrawable();
        virtual ~GameDrawable(){delete program;};
        
        virtual void init() = 0;
        virtual void update(OGEEvents::GameEvent* evt) = 0;
        virtual void render(OGEEvents::GameEvent* evt) = 0;
        virtual void onDestroy() = 0;
        
        void genVBO(int size);
        void genVAO(int size);
        void setPosition(glm::vec3 npos){position = npos;};
        void setScale(glm::vec3 nscale){scale = nscale;};
        void setRotation(glm::vec3 rot){rotation = rot;};
        
        void setTexture(Texture& _texture);
        Texture* getTexture(){return texture;};
        
        glm::vec3 getPosition(){return position;};
        glm::vec3 getScale(){return scale;};
        glm::vec3 getRotation(){return rotation;};
        
        static void needRender(OGEEvents::GameEvent* evt);
        
    public:
        static void instantiate(GameDrawable& obj,glm::vec3 position){
            GameObject::instantiate(obj);
            renderlist.push_back(&obj);
            obj.position = position;
            obj.init();
        };
        
    private:
        static std::vector<GameDrawable*> renderlist;
        
    };
}

#endif /* defined(__OpenGLGame__GameDrawable__) */
