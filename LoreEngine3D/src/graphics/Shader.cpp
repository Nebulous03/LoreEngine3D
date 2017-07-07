#include "Shader.h"
#include <vector>

Shader::Shader()
{
	_program = glCreateProgram();
}

Shader::~Shader()
{
	glDeleteProgram(_program);
}

Shader::Shader(const char* vertex, const char* fragment)
{
	_program = glCreateProgram();
	attachShader(vertex, VERTEX_SHADER);
	attachShader(fragment, FRAGMENT_SHADER);
	linkShader();
}


void Shader::attachShader(const char* path, uint type)
{
	std::string fileString = readFile(path);
	const char* file = fileString.c_str();
	GLuint shader;

	switch (type)
	{
	case VERTEX_SHADER:
		shader = glCreateShader(GL_VERTEX_SHADER); break;
	case FRAGMENT_SHADER:
		shader = glCreateShader(GL_FRAGMENT_SHADER); break;
	case GEOMETRY_SHADER:
		shader = glCreateShader(GL_GEOMETRY_SHADER); break;
	default:
		break;
	}

	glShaderSource(shader, 1, &file, NULL);
	glCompileShader(shader);

	GLint report;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &report);

	if (report == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetShaderInfoLog(shader, length, &length, message);
		std::cout << "Failed to compile shader: (" << path << ", type:" << type << ")!\n" << message << std::endl;	// TODO: REPLACE WITH LOG
		glDeleteShader(shader);
		delete[] message;
		return;
	}

	glAttachShader(_program, shader);

	glDeleteShader(shader);
}

void Shader::linkShader()
{
	glLinkProgram(_program);
	glValidateProgram(_program);
}

void Shader::bind()
{
	glUseProgram(_program);
}

void Shader::unbind()
{
	glUseProgram(0);
}

GLuint Shader::getProgram()
{
	return _program;
}

void Shader::setUniform(const GLchar* name, const int& value)
{
	glUniform1i(glGetUniformLocation(_program, name), value);
}

void Shader::setUniform(const GLchar* name, const float& value)
{
	glUniform1f(glGetUniformLocation(_program, name), value);
}

void Shader::setUniform(const GLchar* name, const Vector2f& value)
{
	glUniform2f(glGetUniformLocation(_program, name), value.x, value.y);
}

void Shader::setUniform(const GLchar* name, const Vector3f& value)
{
	glUniform3f(glGetUniformLocation(_program, name), value.x, value.y, value.z);
}

void Shader::setUniform(const GLchar* name, const Vector4f& value)
{
	glUniform4f(glGetUniformLocation(_program, name), value.x, value.y, value.z, value.w);
}

void Shader::setUniform(const GLchar* name, const Matrix4f& value)
{
	glUniformMatrix4fv(glGetUniformLocation(_program, name), 1, GL_FALSE, value.elements);
}