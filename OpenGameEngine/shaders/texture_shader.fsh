#version 330 core

out vec4 colour;
in vec2 UV;
uniform sampler2D texture_sampler;

void main(){
    colour = texture2D(texture_sampler,UV).rgba;
}