//
//  GameCamera.cpp
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-13.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#include "GameCamera.h"
#include "GameEvent.h"
#include "GameInputManager.h"

using namespace OGECore;

GameCamera* GameCamera::main = NULL;

void GameCamera::init(){
    if (GameCamera::main == NULL) {
        GameCamera::main = this;
    }
    view = glm::mat4(1.f);
}

// Update sets the VIEW parameter for the update GameEvent
// representing movement of the camera
void GameCamera::update(OGEEvents::GameEvent* evt){
    using namespace OGEEvents;
    GameEvent* renderEvt = GameEventManager::eventByName(OGEWindowRenderEvent_NAME);
    if(GameInputManager::getKeyPressed(GLFW_KEY_LEFT)){
        view = glm::translate(view, glm::vec3(5,0,0));
    }
    else if(GameInputManager::getKeyPressed(GLFW_KEY_RIGHT)){
        view = glm::translate(view, glm::vec3(-5,0,0));
    }
    else if(GameInputManager::getKeyPressed(GLFW_KEY_UP)){
        view = glm::translate(view,glm::vec3(0,-5,0));
    }
    else if(GameInputManager::getKeyPressed(GLFW_KEY_DOWN)){
        view = glm::translate(view, glm::vec3(0,5,0));
    }
    renderEvt->setParamMat4("VIEW", view);
}

void GameCamera::onDestroy(){}
