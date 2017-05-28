#include "Game.h"
#include "..\graphics\Graphics.h"

Window* Game::_activeWindow = nullptr;
int Game::_status = GAME_STOPPED;

void Game::start()
{
	// Call other start functions here
	_status = GAME_RUNNING;
	tick();
}

void Game::tick()
{
	while (_status)
	{
		if (glfwWindowShouldClose(_activeWindow->getGLWindow())) {
			stop(); break;
		}

		_activeWindow->updateWindow();

		// Keep running
		glfwPollEvents();
	}
}

void Game::stop()
{
	// Call other stop functions here
	_activeWindow->destroyWindow();
	Graphics::terminateOpenGL();
}

Window* Game::getActiveWindow()
{
	return _activeWindow;
}

void Game::setActiveWindow(Window* window)
{
	glfwMakeContextCurrent(window->getGLWindow());	// Might move back to window
	_activeWindow = window;
}