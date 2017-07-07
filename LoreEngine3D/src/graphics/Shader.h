#pragma once
#include "../utils/FileUtilites.h"
#include "../math/Math.h"
#include <GL\glew.h>

#define VERTEX_SHADER	0 
#define FRAGMENT_SHADER	1
#define GEOMETRY_SHADER	2

#define MAX_SHADER_SIZE	2

class Shader
{
private:
	
	GLuint _program;

public:

	Shader();
	~Shader();

	Shader(const char* vertex, const char* fragment);

	void attachShader(const char* file, uint type);
	void linkShader();
	void bind();
	void unbind();

	GLuint getProgram();

	void setUniform(const GLchar* name, const int& value);
	void setUniform(const GLchar* name, const float& value);
	void setUniform(const GLchar* name, const Vector2f& value);
	void setUniform(const GLchar* name, const Vector3f& value);
	void setUniform(const GLchar* name, const Vector4f& value);

	void setUniform(const GLchar* name, const Matrix4f& value);
};