#version 330 core

layout (location = 0) out vec4 color;

in vec4 vertex_color;

void main()
{
	color = vertex_color; //vec4(1.0, 1.0, 1.0, 1.0);
}
