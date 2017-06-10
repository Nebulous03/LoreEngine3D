#include "graphics\Graphics.h"
#include "graphics\Window.h"
#include "TestGame.h"
#include <iostream>

int main()
{
	TestGame testGame;													// Create Game Instance

	Window window("LoreEngine Test", 640, 480, WINDOWED);				// Create Window
	window.createWindow();												// Create Window

	testGame.linkWindow(&window);										// Link Window

	testGame.getGraphics()->setGLClearColor(0.0f, 0.04f, 0.06f);		// Set Graphics parameters - Move before create?
	//testGame.getGraphics()->setDisplayMode(WINDOWED_FULLSCREEN);
	testGame.getGraphics()->setvSync(true);

	testGame.start();													// Start Game

	system("PAUSE");
	return 0;
}