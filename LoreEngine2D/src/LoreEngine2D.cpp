#include "graphics\Graphics.h"
#include "graphics\Window.h"
#include "TestInstance.h"
#include "TestGame.h"
#include <iostream>

int main()
{
	TestGame testGame;										// Create Game Instance
	Window window("LoreEngine Test", 640, 480, WINDOWED);	// Create Window

	testGame.linkWindow(&window);							// Link Window
	window.createWindow();									// Create Window

	Graphics::setGLClearColor(0.0f, 1.0f, 1.0f);			// Set Graphics parameters - Move before create?

	testGame.start();										// Start Game

	system("PAUSE");
	return 0;
}