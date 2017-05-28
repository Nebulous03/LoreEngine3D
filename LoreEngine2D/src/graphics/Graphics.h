#pragma once

#define GRAPHICS_NONE		000
#define GRAPHICS_OPENGL		100
#define GRAPHICS_DIRECTX12	200	// Maybe...

class Graphics {

private:
	Graphics();
	static bool _vSyncEnabled;

public:

	static int graphicsAPI;
	static bool glInitialized;

	static void initializeOpenGL();
	static void initializeDirectX12();

	static void glErrorCallback(int error, const char* description);

	static void terminateOpenGL();

	static void setvSync(bool vsync);
	static bool isvSyncEnabled();

	static void setGLClearColor(float red, float green, float blue);

};