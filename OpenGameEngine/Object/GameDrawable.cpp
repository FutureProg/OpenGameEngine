//
//  GameDrawable.cpp
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-05.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#include "GameDrawable.h"
#include "GameEvent.h"

using namespace OGECore;

std::vector<GameDrawable*> GameDrawable::renderlist = std::vector<GameDrawable*>();

GameDrawable::GameDrawable():GameObject(){    
}

void GameDrawable::genVBO(int size){
    VBO = new GLuint[size];
    glGenBuffers(size, VBO);

}

void GameDrawable::genVAO(int size){
    VAO = new GLuint[size];
    glGenVertexArrays(size, VAO);
}

void GameDrawable::needRender(OGEEvents::GameEvent* evt){
    for (int i = 0; i < renderlist.size(); i++) {
        renderlist[i]->render(evt);
    }
}

void GameDrawable::setTexture(OGECore::Texture &texture){
    this->texture = &texture;
    addComponent(texture);
    program = new ShaderProgram("texture", "res/texture_shader.vsh", "res/texture_shader.fsh");
    if (_vertices != nullptr) {
        program->setVertices(VBO[0], VAO[0], _vertices, 3, 0);
    }
}