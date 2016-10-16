//
//  GameObject.h
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-05.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#ifndef __OpenGLGame__GameObject__
#define __OpenGLGame__GameObject__

#include <stdio.h>
#include <vector>
#include "Core.h"
#include "GameComponent.h"
#include "GameEvent.h"

namespace OGECore {
    class GameObject : public OGEObject {
        enum Tag{
            PLAYER
        };
        
    public:
        GameObject():ID(number++),OGEObject(){};
        virtual ~GameObject(){
            while (children.size() > 0) {
                GameObject* obj = children.at(0);
                children.erase(children.begin());
                delete obj;
            }
            for (int i = 0; i < GameObject::objects.size(); i++) {
                if (GameObject::objects.at(i)->getID() == getID()) {
                    GameObject::objects.erase(GameObject::objects.begin()+i);
                }
            }
        };
        
        unsigned int getID(){
            return ID;
        };
      
        void addComponent(GameComponent& component){
            components.push_back(&component);
            component.init();
        }
        GameComponent* findComponentByName(char* name){
            for (int i = 0; i < components.size(); i++) {
                if (components[i]->getName() == name) {
                    return components[i];
                }
            }
            return nullptr;
        }
        void removeComponent(GameComponent& component){
            for (int i = 0; i < components.size(); i++) {
                if (components[i] == &component) {
                    components.erase(components.begin() + i);
                    break;
                }
            }
        }
        void removeComponentByName(char* name){
            for (int i = 0; i < components.size(); i++) {
                if (components[i]->getName() == name) {
                    components.erase(components.begin() + i);
                    break;
                }
            }
        }
        
        virtual void init() = 0;// called upon instantiation
        virtual void update(OGEEvents::GameEvent* evt) = 0; // called once per frame
        virtual void onDestroy() = 0;
        
    public:
        static void instantiate(GameObject& obj){
            objects.push_back(&obj);
        };
      
        // Find game objects with the desired tag
        static std::vector<GameObject*> objectsWithTag(Tag tag){
            std::vector<GameObject*> re;
            for (int i = 0; i < GameObject::objects.size(); i++) {
                if (GameObject::objects.at(i)->tag & tag) {
                    re.push_back(GameObject::objects.at(i));
                }
            }
            return re;
        };
      
        // Update the game objects, called by the game window
        static void updateAll(OGEEvents::GameEvent* evt){
            for (int i = 0; i < objects.size(); i++) {
                objects[i]->update(evt);
            }
        };
    private:
        static std::vector<GameObject*> objects;
        
    private:
        static int number;
        
    public:
        std::vector<GameObject*> children;
        const char* name;
        Tag tag;
        
    private:
        unsigned int ID;
        std::vector<GameComponent*> components;
        
    };
}

#endif /* defined(__OpenGLGame__GameObject__) */
