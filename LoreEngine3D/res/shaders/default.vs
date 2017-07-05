#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

uniform mat4 projection = mat4(1.0);
uniform mat4 view = mat4(1.0);
uniform mat4 model = mat4(1.0);

out DATA
{
	vec4 position;
	vec4 color;
}
data_out;

void main()
{
	gl_Position = projection * view * model * position;
	data_out.color = color;
}