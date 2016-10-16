//
//  GameInputManager.cpp
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-20.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#include "GameInputManager.h"
#include "GameEvent.h"
using namespace OGEEvents;

std::map<int,int> GameInputManager::keystates = std::map<int,int>();

GameInputManager::GameInputManager(GLFWwindow &window){
    glfwSetKeyCallback(&window, GameInputManager::key_callback);
};