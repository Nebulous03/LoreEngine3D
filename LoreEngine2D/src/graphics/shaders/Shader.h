#pragma once

#define MAX_SHADER_SIZE 2

typedef unsigned int uint;

class Shader
{
private:
	uint _program;
	uint _shaders[MAX_SHADER_SIZE];
public:
	Shader();
	
	void attachShader(const char* file);

	void bind();
	void unbind();
};