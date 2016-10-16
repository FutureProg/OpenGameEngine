//
//  Texture.cpp
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-07.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#include "Texture.h"
using namespace OGECore;

Texture::Texture(){
    name = "Texture";
    glGenBuffers(1, &uvBuffer);

}

Texture::~Texture(){
  glDeleteBuffers(1, &uvBuffer);
}

void Texture::init(){
    static const GLfloat g_uv_buffer_data[]{
        0.f,0.f,
        0.f,1.f,
        1.f,1.f,
        1.f,0.f
    };
    glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
}

void Texture::update(){
    
}

void Texture::apply(ShaderProgram& program){
    glActiveTexture(GL_TEXTURE0);
    
}
