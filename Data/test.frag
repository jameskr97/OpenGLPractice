#version 410 core

in VS_OUT {
    vec4 vs_color;
} vs_in;

out vec4 color;

void main(void){

    color = vs_in.vs_color;
}