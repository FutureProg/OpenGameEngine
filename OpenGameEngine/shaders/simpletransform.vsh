#version 330 core

layout(location=1) in vec3 vertex_location;
uniform mat4 MVP;

void main(){
    gl_Position = MVP * vec4(vertex_location,1.f);
}