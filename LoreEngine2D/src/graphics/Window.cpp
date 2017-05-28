#include "../game/Game.h"
#include "Window.h"
#include <iostream>

Window::Window(char* title = "LoreEngine2D - Core", int width = 640, int height = 480, int windowMode = WINDOWED) :
	_title(title), _width(width), _height(height), _windowMode(windowMode) {}

// Generates the OpenGL window
void Window::createWindow()
{
	if(!Graphics::glInitialized)
		Graphics::initializeOpenGL();

	setVisable(GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, LORE_GL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, LORE_GL_VERSION_MINOR);
	glfwWindowHint(GLFW_FOCUSED, true);

	if (Graphics::glInitialized) {

		switch (_windowMode)
		{
		default:
		{
			_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);
			break;
		}
		case WINDOWED_FULLSCREEN :
		{
			const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

			glfwWindowHint(GLFW_RED_BITS, mode->redBits);
			glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
			glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
			glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

			_window = glfwCreateWindow(mode->width, mode->height, _title, glfwGetPrimaryMonitor(), NULL);
			break;
		}
		case FULLSCREEN :
		{
			_window = glfwCreateWindow(_width, _height, _title, glfwGetPrimaryMonitor(), NULL);
			break;
		}
		}

		if (!_window)
			std::cout << "Error! : Failed to generate GLFW Window!" << std::endl;
	}
	else {
		std::cout << "Error! : OpenGL must be initialized before a window can be generated!" << std::endl;
	}

	Game::setActiveWindow(this);	// Not sure if I like this here...
	setVisable(GL_TRUE);
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

void Window::setWindowMode(int mode)
{
	_windowMode = mode;
}

int Window::getWindowMode() const
{
	return _windowMode;
}

void Window::setVisable(bool visable)
{
	_visable = visable;
	glfwWindowHint(GLFW_VISIBLE, visable ? 0 : 1);
}

bool Window::isVisable() const
{
	return _visable;
}

int Window::getWidth() const { return _width; }
int Window::getHeight() const { return _height; }

GLFWwindow* Window::getGLWindow() const { return _window; }