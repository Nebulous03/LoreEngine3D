#include "Graphics.h"
#include <iostream>
#include <GLFW\glfw3.h>

int Graphics::graphicsAPI = GRAPHICS_NONE;
bool Graphics::glInitialized = false;
bool Graphics::_vSyncEnabled = false;

// Initializes OpenGL graphics
void Graphics::initializeOpenGL()
{
	// Initialize OpenGL API
	if (glfwInit() == GLFW_FALSE)
		std::cout << "Fatal Error! : OpenGL failed to initialize! (glfwInit() = GLFW_FALSE)" << std::endl;
	else
		std::cout << "OpenGL initialized successfully!" << std::endl;

	// Set GL error callback
	// (Runs when GL errors)
	glfwSetErrorCallback(glErrorCallback);

	graphicsAPI = GRAPHICS_OPENGL;
	glInitialized = true;
}

void Graphics::glErrorCallback(int error, const char* description)
{
	std::cout << "Fatal Error! : OpenGL encountered an internal error! [" << error << "]\n\t" << description << std::endl;
}

void Graphics::terminateOpenGL()
{
	glfwTerminate();
	std::cout << "OpenGL successfully terminated." << std::endl;
}

void Graphics::initializeDirectX12()
{
	// Haha thats funny
	// Maybe in the future...
}

void Graphics::setGLClearColor(float red, float green, float blue) {
	glClearColor(red, green, blue, 1.0f);
}

void Graphics::setvSync(bool vsync)
{
	glfwSwapInterval(vsync);
	_vSyncEnabled = vsync;
}

bool Graphics::isvSyncEnabled()
{
	return _vSyncEnabled;
}