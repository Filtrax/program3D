#version 420

layout(location=0) out vec4 vFragColor;
in vec3 output_color;

layout(std140, binding = 0) uniform Modifier {
float strength;
vec3  color; 
};

void main() {
    vFragColor = vec4(output_color.xyz, 1.0);
}
