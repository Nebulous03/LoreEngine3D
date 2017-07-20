#include "graphics\Graphics.h"
#include "graphics\Window.h"
#include "TestGame.h"
#include "math\Math.h"
#include <iostream>

int main()
{
	TestGame testGame;													// Create Game Instance

	Window window("LoreEngine Test", 640, 480, WINDOWED);				// Create Window
	//Window window("LoreEngine Test", 1920, 1080, WINDOWED);
	window.createWindow();												// Create Window

	testGame.linkWindow(&window);										// Link Window

	std::cout << testGame.getGraphics().getGLSpecs().c_str();

	testGame.getGraphics().setGLClearColor(0.0f, 0.04f, 0.06f);
	//testGame.getGraphics()->setDisplay(WINDOWED_FULLSCREEN, 640, 480);
	testGame.getGraphics().setvSync(false);

	testGame.start();													// Start Game

	//system("PAUSE");
	return 0;
}