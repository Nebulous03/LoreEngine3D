#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 shader_color;

void main()
{
	color = shader_color; //vec4(1.0, 1.0, 1.0, 1.0);
}
