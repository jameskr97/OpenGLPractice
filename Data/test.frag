#version 400 core

in VS_OUT {
    vec4 vs_color;
} vs_in;

out vec4 color;

void main(void){
    color = vs_in.vs_color; // vec4(0.06, 0.11, 0.42, 1.0);
}