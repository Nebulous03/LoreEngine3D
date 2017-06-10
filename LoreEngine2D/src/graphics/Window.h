#pragma once
#include <GLFW\glfw3.h>
#include "Graphics.h"

class Graphics; // I dont like this...

class Window {

private:

	GLFWwindow* _window;

	char* _title	= "LoreEngine2D - Game";
	int   _width	= 640;
	int   _height	= 480;

	Graphics* _graphics = nullptr;

	bool  _visable  = false;

public:
	Window(char*, int, int, int);
	void createWindow();
	void build();
	void rebuild();
	void destroyWindow() const;
	void updateWindow() const;
	void setVisable(bool visable);
	bool isVisable() const;
	int getHeight() const;
	int getWidth() const;
	GLFWwindow* getGLWindow() const;
	Graphics* getGraphics();
	~Window();

};