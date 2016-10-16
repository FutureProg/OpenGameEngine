//
//  main.cpp
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-06-30.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#define GLM_FORCE_RADIANS

#include <iostream>
#include <string.h>
#include <stdio.h>

#include "shader.hpp"
#include "GameWindow.h"
#include "Shapes.h"

GLFWwindow *window;
int width = 400,height = 400;
using namespace OGECore;
void mouseCallback(GLFWwindow* window,int button,int action,int mods);

int main(int argc, const char * argv[]) {
    GameWindow window("Test",400,400);
    ShapeTriangle* triangle = new ShapeTriangle();
    GameShape::instantiate(*triangle, glm::vec3(0.f,0.f,0.f));
    triangle = new ShapeTriangle();
    GameShape::instantiate(*triangle, glm::vec3(50.f,50.f,0.f));
    triangle = new ShapeTriangle();
    GameShape::instantiate(*triangle, glm::vec3(100.f,0.f,0.f));
    ShapeSquare* square = new ShapeSquare();
    GameShape::instantiate(*square, glm::vec3(-50.f,0.f,0.f));
    /*if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW!\n");
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    int maj, min;
    glfwGetVersion(&maj, &min, NULL);
    printf("OpenGL Version: %i.%i\n",maj,min);
    
    window = glfwCreateWindow(width, height, "BLA", NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Failed to create the GLFW Window");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glEnable(GL_DEPTH);
    
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_FALSE);
    glfwSetInputMode(window, GLFW_CURSOR_NORMAL, GL_TRUE);
    glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GL_FALSE);
    glfwSetMouseButtonCallback(window, mouseCallback);
    
    GLuint VBO;
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    static const GLfloat vertices[] = {-50.0,0.0,0.0,50.0,50.0,0.0};
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),&vertices[0],GL_STATIC_DRAW);
    
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBindVertexArray(VAO);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,0,(GLvoid*)(0 * sizeof(GL_FLOAT)));
    
    GLuint programID = LoadShaders("res/simpletransform.vsh","res/singlecolor.fsh");
    glUseProgram(programID);
    GLuint matrixID = glGetUniformLocation(programID,"MVP");
    GLuint posID = glGetAttribLocation(programID,"position");
    printf("matrixID: %i | vertexID: %i",matrixID,posID);
    
    glBindVertexArray(NULL);
    glBindBuffer(GL_ARRAY_BUFFER,NULL);
    
    glm::mat4 proj = glm::ortho(-float(width)*2, float(width)*2.f, -float(height)*2.f, float(height)*2.f, -10.f, 100.f);
    glm::mat4 view = glm::mat4();
    glm::mat4 model = glm::mat4(1.f);
    model = glm::scale(model, glm::vec3(3,3,3));
    glm::mat4 MVP = proj * view * model;
    
    do{
        glfwPollEvents();
        glfwGetWindowSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        glUseProgram(programID);
        

        glBindBuffer(GL_ARRAY_BUFFER,VBO);
        glBindVertexArray(VAO);
        glUniformMatrix4fv(matrixID,1,GL_FALSE,&MVP[0][0]);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glFlush();
        
        glBindVertexArray(NULL);
        glBindBuffer(GL_ARRAY_BUFFER,NULL);
        
        glfwSwapBuffers(window);
    }while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
    
    glDeleteBuffers(1,&VBO);
    glDeleteProgram(programID);
    glDeleteVertexArrays(1,&VBO);
    glfwTerminate();*/
    
    return window.execute();
}

void mouseCallback(GLFWwindow* window,int button,int action,int mods){
    if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS) {
        printf("Pressed mouse button");
    }
}
