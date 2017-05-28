#pragma once
#include <GLFW\glfw3.h>
#include "Graphics.h"

class Window {

private:

	GLFWwindow* _window;

	char* _title	= "LoreEngine2D - Game";
	int   _width	= 640;
	int   _height	= 480;

public:
	void createWindow(char*, int, int);
	void destroyWindow() const;
	void updateWindow() const;
	int getHeight() const;
	int getWidth() const;
	GLFWwindow* getGLWindow() const;

};