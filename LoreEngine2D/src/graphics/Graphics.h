#pragma once
#include "Window.h"
#include <string>

#define LORE_GL_VERSION_MAJOR	4		// LoreEngine max OpenGL version
#define LORE_GL_VERSION_MINOR	0		// LoreEngine min OpenGL version

#define GRAPHICS_NONE			000
#define GRAPHICS_OPENGL			100
#define GRAPHICS_DIRECTX12		200		// Maybe...

class Window; // I dont like this
typedef unsigned int DisplayMode; // especially this

class Graphics {

private:
	bool _vSyncEnabled;
	Window* _window;

public:
	Graphics(Window& window);

	int graphicsAPI;
	bool glInitialized;
	void initializeOpenGL();
	void initializeDirectX12();

	void setvSync(bool vsync);
	bool isvSyncEnabled();
	void setGLClearColor(float red, float green, float blue);
	void resizeWindow(int width, int height);
	void setDisplay(DisplayMode displayMode, int width, int height);
	void setDisplayMode(DisplayMode displayMode);
	int  getDisplayMode();
	void terminateOpenGL();

	const char* getOpenGLVersion();
	std::string getGLSpecs();

	static void glErrorCallback(int error, const char* description);
};