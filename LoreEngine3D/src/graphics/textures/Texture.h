#pragma once
#include <GL\glew.h>

struct Texture
{

	GLuint id = 0;

	GLsizei width  = 0;
	GLsizei height = 0;
	GLsizei bits   = 0;

	Texture(GLuint id, unsigned int width, unsigned int height, unsigned int bits);
	~Texture();

	void bind();
	void unbind();

};