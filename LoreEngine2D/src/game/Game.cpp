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

void Game::loadInstance(const char* instanceName, Instance& instance)
{
	_activeInstances[instanceName] = &instance;
	// Do other things to instance (load)
}

void Game::unloadInstance(const char* instanceName)
{
	Instance* inst = _activeInstances[instanceName];
	// Do other things to instance (unload)
	_activeInstances.erase(instanceName);
}

void Game::clearAllInstances()
{
	Instance* inst;
	for (std::map<const char*, Instance*>::iterator i = _activeInstances.begin(); i != _activeInstances.end(); ++i)
	{
		inst = i->second;
		// Do other things to instance (unload)
	}
	_activeInstances.clear();
}

void Game::updateAllInstances()
{

}

Instance* Game::getActiveInstances()
{
	
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