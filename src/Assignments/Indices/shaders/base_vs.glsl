#version 410

layout(location=0) in  vec4 a_vertex_position;
layout(location=1) in  vec3 input_color;
out vec3 output_color;


void main() {
    gl_Position = a_vertex_position;
    output_color = input_color;
}
