//
//  GameWindow.cpp
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-04.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#include "GameWindow.h"
#include "GameEvent.h"
#include "GameDrawable.h"
#include "ShaderProgram.h"
using namespace OGECore;
using namespace OGEEvents;

GameWindow::GameWindow(const char* title,int width,int height):renderEvent(OGEEvents::GameEvent(OGEEventType_Render,this)),title(title),width(width),height(height),updateEvent(OGEEvents::GameEvent(OGEEventType_Update,this)),OGEObject(){
    if (!glfwInit()) {
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
    
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Failed to create the GLFW Window");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH);
    
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_FALSE);
    glfwSetInputMode(window, GLFW_CURSOR_NORMAL, GL_TRUE);
    glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GL_FALSE);
    setClearColour(OGEColorGreen);
    
    ShaderProgram program("standard","res/simpletransform.vsh","res/singlecolor.fsh");
    renderEvent.name = OGEWindowRenderEvent_NAME;
    GameEventManager::registerEvent(renderEvent);
    OGEEvents::GameEventManager::registerDelegateByName(OGEWindowRenderEvent_NAME, GameDrawable::needRender);
    
    updateEvent.name = OGEWindowUpdateEvent_NAME;
    GameEventManager::registerEvent(updateEvent);
    GameEventManager::registerDelegateByName(OGEWindowRenderEvent_NAME, GameObject::updateAll);
    deltaTime = 0.0;
    lastTime = time(0);
    gameInputManager = new OGEEvents::GameInputManager(*window);
}

int GameWindow::execute(){
    do{
        glfwPollEvents();
        update();
        render();
        glfwSwapBuffers(window);
    }while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
    glfwTerminate();
    return EXIT_SUCCESS;
}

void GameWindow::update(){
    glfwGetWindowSize(window, &width, &height);
    deltaTime = time(0) - lastTime;
    lastTime += deltaTime;
    updateEvent.setParamLongDouble("DELTA_TIME", deltaTime);
    updateEvent.setParamInt("WINDOW_WIDTH", width);
    updateEvent.setParamInt("WINDOW_HEIGHT", height);
    gameInputManager->update(&updateEvent);
    updateEvent.callWait();
    camera.update(&updateEvent);
}

void GameWindow::render(){
    glViewport(0, 0, width*2, height*2);
    glClear(GL_COLOR_BUFFER_BIT);

    glm::mat4 proj = glm::ortho(-float(width)*2, float(width)*2.f, -float(height)*2.f, float(height)*2.f, -10.f, 100.f);
    renderEvent.setParamMat4("PROJ", proj);
    renderEvent.callWait();
    
    glFlush();
}

void GameWindow::setSize(int width, int height){
    this->width = width;
    this->height = height;
}

void GameWindow::setTitle(const char * title){
    this->title = title;
}

void GameWindow::setClearColour(Color color){
    clearColour = color;
    printf("r: %f g: %f b:%f a:%f",color.r/255.f,color.g/255.f,color.b/255.f,color.alpha/255.f);
    glClearColor(color.r/255.f, color.g/255.f, color.b/255.f, color.alpha/255.f);
}

Color GameWindow::getClearColour(){
    return clearColour;
}

void GameWindow::getSize(int *rewidth, int *reheight){
    rewidth = &width;
}

const char* GameWindow::getTitle(){
    return this->title;
}

GameWindow::~GameWindow(){
    delete gameInputManager;
}

