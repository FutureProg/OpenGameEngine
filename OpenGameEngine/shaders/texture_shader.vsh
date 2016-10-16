#version 330 core

layout(location=1) in vec3 vertex_location;
layout(location=2) in vec2 UV_coords;
uniform mat4 MVP;

out vec2 UV;

void main(){
    gl_Position = MVP * vec4(vertex_location,1.f);
    UV = UV_coords;
}