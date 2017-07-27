#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texCoord;
layout (location = 3) in vec3 normal;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

out vec4 _color;
out vec2 _texCoord;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0);
	_color = vec4(clamp(position, 0.0, 1.0), 1.0);
	_texCoord = texCoord;
}