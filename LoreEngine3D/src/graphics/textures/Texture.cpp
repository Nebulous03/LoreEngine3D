#include "Texture.h"

Texture::Texture(GLuint id, unsigned int width, unsigned int height, unsigned int bits) :
id(id), width(width), height(height), bits(bits) {}

Texture::~Texture()
{

}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}