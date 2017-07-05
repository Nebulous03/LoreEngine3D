#include "Shader.h"
#include "../../utils/FileHander.h"

Shader::Shader()
{
	
}

void Shader::attachShader(const char* file)
{
	std::string shader = loadAsString(file);
}

void Shader::bind()
{

}

void Shader::unbind()
{

}