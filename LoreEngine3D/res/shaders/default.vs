#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

uniform mat4 projection = mat4(1.0);
uniform mat4 view = mat4(1.0);
uniform mat4 model = mat4(1.0);

out vec4 vertex_color;

void main()
{
	gl_Position = projection * view * model * position;
	vertex_color = color;
}