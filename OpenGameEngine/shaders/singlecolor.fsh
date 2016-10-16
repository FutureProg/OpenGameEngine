#version 330 core


out vec4 colour;
uniform vec4 color_primary;

void main(){
    //Output color = red
    colour = color_primary;
}