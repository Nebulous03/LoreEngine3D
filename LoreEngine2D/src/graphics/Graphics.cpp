#include "Graphics.h"
#include <windows.h> // BADDDDD
#include <iostream>
#include <GLFW\glfw3.h>

Graphics::Graphics(Window& window)
{
	graphicsAPI = GRAPHICS_NONE;
	glInitialized = false;
	_vSyncEnabled = false;
	_window = &window;
}

// Initializes OpenGL graphics
void Graphics::initializeOpenGL()
{
	// Initialize OpenGL API
	if (glfwInit() == GLFW_FALSE)
		std::cout << " Fatal Error! : OpenGL failed to initialize! (glfwInit() = GLFW_FALSE)" << std::endl;
	else
		std::cout << " OpenGL initialized successfully!" << std::endl;

	// Set GL error callback
	// (Runs when GL errors)
	glfwSetErrorCallback(glErrorCallback);

	graphicsAPI = GRAPHICS_OPENGL;
	glInitialized = true;
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

void Graphics::resizeWindow(int width, int height)
{
	_window->resize(width, height);
}

void Graphics::setDisplay(DisplayMode displayMode, int width, int height)
{
	resizeWindow(width, height);
	setDisplayMode(displayMode);
}

void Graphics::setDisplayMode(DisplayMode displayMode)
{
	_window->setDisplayMode(displayMode);
}

int Graphics::getDisplayMode()
{
	return _window->getDisplayMode();
}

void Graphics::glErrorCallback(int error, const char* description)
{
	std::cout << " Fatal Error! : OpenGL encountered an internal error! [" << error << "]\n\t" << description << std::endl;
}

void Graphics::terminateOpenGL()
{
	glfwTerminate();
	std::cout << " OpenGL successfully terminated." << std::endl;
}

const char* Graphics::getOpenGLVersion()
{
	return 0;
}

std::string Graphics::getGLSpecs()
{
	std::string result;

	char path[MAX_PATH];
	std::string(path, GetModuleFileName(NULL, path, MAX_PATH));

	result += " ------------------------------------------------------------------------------------------------\n";
	result = result + "  OPENGL VERSION: " + (char*)(glGetString(GL_VERSION)) + "\n";
	result = result + "  GRAPHICS HARDWARE: " + (char*)(glGetString(GL_RENDERER)) + "\n";
	result = result + "  VENDORS: " + (char*)(glGetString(GL_VENDOR)) + "\n";
	result = result + "  DIRECTORY: " + path + "\n";
	result += " ------------------------------------------------------------------------------------------------\n";

	return result;
}