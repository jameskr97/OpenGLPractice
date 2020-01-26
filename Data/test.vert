#version 410 core

out VS_OUT {
    vec4 vs_color;
} vs_out;

void main(void) {
    const vec4 vertices[3] = vec4[3](
        vec4(0.5, -0.5, 0.5, 1.0),
        vec4(-0.5, -0.5, 0.5, 1.0),
        vec4(0.0, 0.5, 0.5, 1.0));

    const vec4 colors[3] = vec4[3](
        vec4(1.0, 0.0, 0.0, 1.0),
        vec4(0.0, 1.0, 0.0, 1.0),
        vec4(0.0, 0.0, 1.0, 1.0));

    gl_Position = vertices[gl_VertexID];
    vs_out.vs_color = colors[gl_VertexID];
}
