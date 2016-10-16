//
//  ShaderProgram.cpp
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-08.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#include "ShaderProgram.h"
#include "shader.hpp"

std::map<const char*, ShaderProgram*> ShaderProgram::programs;

ShaderProgram::ShaderProgram(const char* name,const char* vertexFilePath, const char* fragmentFilePath){
    shader = LoadShaders(vertexFilePath, fragmentFilePath);
    this->name = name;
    programs[name] = this;
}

ShaderProgram ShaderProgram::getProgramByName(const char* name){
    if (programs.find(name) != programs.end()) {
        return *programs[name];
    }
    return getProgramByName("standard");
}

void ShaderProgram::use(){
    glUseProgram(shader);
}

void ShaderProgram::unbind(){
    glUseProgram(NULL);
}

void ShaderProgram::setColorPrimary(OGECore::Color col){
    printf("SET");
    int location = getUniformLocation("color_primary");
    glProgramUniform4f(shader,location, col.r/255.f, col.g/255.f, col.b/255.f, col.alpha/255.f);
}

void ShaderProgram::setVertices(GLuint VBO, GLuint VAO, GLfloat vertices[], int size, int stride){
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBindVertexArray(VAO);
    int location = getAttributeLocation("vertex_location");
    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location,size,GL_FLOAT,GL_FALSE,stride,(GLvoid*)(0 * sizeof(GL_FLOAT)));
    glBindBuffer(GL_ARRAY_BUFFER, NULL);
    glBindVertexArray(NULL);
}

int ShaderProgram::getUniformLocation(const char* name){
    return glGetUniformLocation(shader, name);
}

int ShaderProgram::getAttributeLocation(const char *name){
    return glGetAttribLocation(shader, name);
}

ShaderProgram::~ShaderProgram(){
    glDeleteProgram(shader);
}