#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "Graphics.h"

#define WINDOWED				0
#define WINDOWED_FULLSCREEN		1
#define FULLSCREEN				2

typedef unsigned int DisplayMode;

class Graphics;

class Window {

private:

	GLFWwindow* _window;

	char* _title	= "LoreEngine2D - Game";
	int   _width	= 640;
	int   _height	= 480;

	DisplayMode _displayMode = WINDOWED;

	Graphics* _graphics = nullptr;

	bool  _visable  = false;

	void (*windowResizeCallback)(Window& window, int width, int height);

	friend void setSize(Window& window, const int width, const int height);
	friend void window_size_callback(GLFWwindow* window, int width, int height);

public:
	Window(char*, int, int, DisplayMode);
	void setResizeCallback(void* resizeCallback);
	void createWindow();
	void build();
	void destroyWindow() const;
	void clear() const;
	void update() const;
	void resize(int, int);
	void setDisplayMode(int);
	DisplayMode getDisplayMode();
	void setVisable(bool);
	bool isVisable() const;
	int getHeight() const;
	int getWidth() const;
	GLFWwindow* getGLWindow() const;
	Graphics* getGraphics();
	~Window();
};
