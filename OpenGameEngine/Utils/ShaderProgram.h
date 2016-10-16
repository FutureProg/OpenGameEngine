//
//  ShaderProgram.h
//  OpenGLGame
//
//  Created by Nickolas Morrison on 2015-07-08.
//  Copyright (c) 2015 Nick Morrison. All rights reserved.
//

#ifndef __OpenGLGame__ShaderProgram__
#define __OpenGLGame__ShaderProgram__

#include <stdio.h>
#include <map>
#include "Core.h"

class ShaderProgram {
public:
    static ShaderProgram getProgramByName(const char* name);
    static void unbind();
    
public:
    ShaderProgram(const char* name,const char* vertexFilePath, const char* fragmentFilePath);
    ~ShaderProgram();
    
    void use();
    
    void setColorPrimary(OGECore::Color col);
    void setVertices(GLuint VBO, GLuint VAO, GLfloat vertices[], int size, int stride);
    
    int getUniformLocation(const char* name);
    int getAttributeLocation(const char* name);
    
private:
    GLuint shader;
    const char* name;
    static std::map<const char*, ShaderProgram*> programs;
    
};

#endif /* defined(__OpenGLGame__ShaderProgram__) */
