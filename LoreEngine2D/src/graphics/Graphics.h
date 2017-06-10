#pragma once
#include "Window.h"

#define LORE_GL_VERSION_MAJOR	4		// LoreEngine max OpenGL version
#define LORE_GL_VERSION_MINOR	0		// LoreEngine min OpenGL version

#define WINDOWED				0
#define WINDOWED_FULLSCREEN		1
#define FULLSCREEN				2

#define GRAPHICS_NONE			000
#define GRAPHICS_OPENGL			100
#define GRAPHICS_DIRECTX12		200		// Maybe...

class Window;	// I dont like this....

class Graphics {

private:
	bool _vSyncEnabled;
	Window* _window;
	int _displayMode = WINDOWED;

public:
	Graphics(Window& window);

	int graphicsAPI;
	bool glInitialized;

	void initializeOpenGL();
	void initializeDirectX12();

	static void glErrorCallback(int error, const char* description);

	void terminateOpenGL();

	void setvSync(bool vsync);
	bool isvSyncEnabled();

	void setGLClearColor(float red, float green, float blue);

	void setDisplayMode(int displayMode);
	int  getDisplayMode();
};