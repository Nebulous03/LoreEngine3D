#pragma once
#include <GLFW\glfw3.h>
#include "Graphics.h"

#define LORE_GL_VERSION_MAJOR	4		// LoreEngine max OpenGL version
#define LORE_GL_VERSION_MINOR	0		// LoreEngine min OpenGL version

#define WINDOWED				0
#define WINDOWED_FULLSCREEN		1
#define FULLSCREEN				2

class Window {

private:

	GLFWwindow* _window;

	char* _title	= "LoreEngine2D - Game";
	int   _width	= 640;
	int   _height	= 480;

	int   _windowMode = WINDOWED;

	bool  _visable  = false;

public:
	Window(char*, int, int, int);
	void createWindow();
	void destroyWindow() const;
	void updateWindow() const;
	void setWindowMode(int mode);
	int getWindowMode() const;
	void setVisable(bool visable);
	bool isVisable() const;
	int getHeight() const;
	int getWidth() const;
	GLFWwindow* getGLWindow() const;

};