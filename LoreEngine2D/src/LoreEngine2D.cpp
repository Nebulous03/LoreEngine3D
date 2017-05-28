#include "game\game.h" 
#include "graphics\Graphics.h"
#include "graphics\Window.h"
#include <iostream>

int main()
{
	Window win;
	win.createWindow("LoreEngine Test", 640, 480);

	Graphics::setGLClearColor(0.0f, 1.0f, 1.0f);

	Game::start();

	system("PAUSE");
	return 0;
}