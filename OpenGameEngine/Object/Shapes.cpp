//
//  Shape.cpp
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-07.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#include "Shapes.h"
#include "GameEvent.h"

using namespace OGECore;

void ShapeTriangle::init(){
    genVBO(1);
    genVAO(1);
    program->setColorPrimary(OGEColorBlue);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    GLfloat vertices[] = {
        -50.f,0.f,1.f,
        0.f, 50.f,1.f,
        50.f,0.f,1.f
    };
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);
    program->setVertices(VBO[0], VAO[0], vertices, 3, 0);
    setScale(glm::vec3(2.f));
}

void ShapeTriangle::update(OGEEvents::GameEvent* evt){
}

void ShapeTriangle::render(OGEEvents::GameEvent* evt){
    program->use();
    model = glm::scale(glm::mat4(), scale);
    model = glm::translate(model, position);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBindVertexArray(VAO[0]);
    glm::mat4 view = evt->getParamMat4("VIEW");
    glm::mat4 proj = evt->getParamMat4("PROJ");
    glm::mat4 MVP = proj * view * model;
    glUniformMatrix4fv(program->getUniformLocation("MVP"),1,GL_FALSE,&MVP[0][0]);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindBuffer(GL_ARRAY_BUFFER, NULL);
    glBindVertexArray(NULL);
}

void ShapeTriangle::onDestroy(){}

ShapeTriangle::~ShapeTriangle(){
    
}

#pragma mark - ShapeSquare Class Definition

void ShapeSquare::init(){
    genVBO(1);
    genVAO(1);    
    program->setColorPrimary(OGEColorRed);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    GLfloat vertices[] = {
        -50.f, 0.f, 1.f,
        -50.f, 50.f, 1.f,
        0.f, 50.f,1.f,
        0.f, 0.f, 1.f
    };
    _vertices = vertices;
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);
    program->setVertices(VBO[0], VAO[0], vertices, 3, 0);
    setScale(glm::vec3(2.f));
}

void ShapeSquare::update(OGEEvents::GameEvent *evt){
    
}

void ShapeSquare::render(OGEEvents::GameEvent *evt){
    program->use();
    if (texture != nullptr) {
        texture->apply(*program);
    }
    model = glm::scale(glm::mat4(), scale);
    model = glm::translate(model, position);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBindVertexArray(VAO[0]);
    glm::mat4 MVP = evt->getParamMat4("PROJ") * evt->getParamMat4("VIEW") * model;
    glUniformMatrix4fv(program->getUniformLocation("MVP"), 1, GL_FALSE, &MVP[0][0]);
    
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    
    glBindBuffer(GL_ARRAY_BUFFER, NULL);
    glBindVertexArray(NULL);
}

void ShapeSquare::onDestroy(){
    
}

ShapeSquare::~ShapeSquare(){
    
}
