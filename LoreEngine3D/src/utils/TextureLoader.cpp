#include "TextureLoader.h"
#include <fstream>
#include <FreeImage.h>
#include <iostream>

Texture* createTexture(const char* path)
{
	std::ifstream file(path);
	if (!file.good())
	{
		std::cout << " Error Loading Texture! Could not locate [" << path << "]!" << std::endl;
		return nullptr;
	}

	FREE_IMAGE_FORMAT format = FIF_UNKNOWN;
	FIBITMAP *bitmap = nullptr;
	BYTE* pixels = nullptr;

	unsigned int width(0), height(0);

	GLuint gl_texID;

	format = FreeImage_GetFileType(path, 0);

	if (format == FIF_UNKNOWN)
		format = FreeImage_GetFIFFromFilename(path);

	if (format == FIF_UNKNOWN) {
		std::cout << " Error Loading Texture! Unknown file type!" << std::endl;
		return nullptr;
	}

	if (FreeImage_FIFSupportsReading(format))
		bitmap = FreeImage_Load(format, path);

	if (!bitmap) {
		std::cout << " Error Loading Texture! Unable to load bitmap!" << std::endl;
		return nullptr;
	}

	pixels = FreeImage_GetBits(bitmap);

	unsigned int bits  = FreeImage_GetBPP(bitmap);
	unsigned int pitch = FreeImage_GetPitch(bitmap);

	width = FreeImage_GetWidth(bitmap);
	height = FreeImage_GetHeight(bitmap);

	if ((pixels == 0) || (width == 0) || (height == 0))
		return nullptr;

	glGenTextures(1, &gl_texID);
	glBindTexture(GL_TEXTURE_2D, gl_texID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, pixels);

	glBindTexture(GL_TEXTURE_2D, 0);

	FreeImage_Unload(bitmap);

	std::cout << " Texture [" << path << "] loaded Successfully" << std::endl;

	return new Texture(gl_texID, width, height, bits);
}