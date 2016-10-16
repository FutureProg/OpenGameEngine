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
    return window.execute();
}

void mouseCallback(GLFWwindow* window,int button,int action,int mods){
    if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS) {
        printf("Pressed mouse button");
    }
}
