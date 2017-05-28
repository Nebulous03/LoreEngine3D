#include "../game/Game.h"
#include "Window.h"
#include <iostream>

#define LORE_GL_VERSION_MAJOR 4		// LoreEngine max OpenGL version
#define LORE_GL_VERSION_MINOR 0		// LoreEngine min OpenGL version

// Generates the OpenGL window
void Window::createWindow(char* title = "LoreEngine2D - Core", int width = 640, int height = 480)
{
	_title  = title; _width  = width; _height = height;

	if(!Graphics::glInitialized)
		Graphics::initializeOpenGL();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, LORE_GL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, LORE_GL_VERSION_MINOR);

	if (Graphics::glInitialized) {

		_window = glfwCreateWindow(_width, _height, _title, 0, 0);

		if (!_window)
			std::cout << "Error! : Failed to generate GLFW Window!" << std::endl;
	}
	else {
		std::cout << "Error! : OpenGL must be initialized before a window can be generated!" << std::endl;
	}

	Game::setActiveWindow(this);	// Not sure if I like this here...
}

void Window::updateWindow() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwSwapBuffers(_window);
}

void Window::destroyWindow() const
{
	glfwDestroyWindow(_window);
}

int Window::getWidth() const { return _width; }
int Window::getHeight() const { return _height; }

GLFWwindow* Window::getGLWindow() const { return _window; }