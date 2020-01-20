#version 410 core

in VS_OUT {
    vec4 vs_color;
} vs_in;

out vec4 color;

void main(void){
    color = vec4(1.0, 1.0, 1.0, 1.0);
}