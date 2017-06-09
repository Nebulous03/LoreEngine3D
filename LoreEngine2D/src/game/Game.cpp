#include "Game.h"
#include "..\graphics\Graphics.h"
#include <iostream>

int Game::_status = GAME_STOPPED;
Window* Game::_activeWindow = nullptr;
Instance* Game::_activeInstance = nullptr;
TickHandler* Game::_tickHandler = nullptr;

Game::Game()
{
	_tickHandler = new TickHandler(*this, 60.0);
}

void Game::start()
{
	// Call other start functions here
	_status = GAME_RUNNING;	//Mode to tickhandler
	onStart();
	_tickHandler->run();
}

void Game::stop()
{
	// Call other stop functions here
	onStop();
	unloadActiveInstance();
	_activeWindow->destroyWindow();
	Graphics::terminateOpenGL();
}

void Game::loadInstance(Instance* instance)
{
	// TODO: Check for active instance
	_activeInstance = instance;
	_activeInstance->onLoad();
}

void Game::unloadActiveInstance()
{
	if (_activeInstance) {
		_activeInstance->onUnload();
		_activeInstance = nullptr;
	}
	else {
		std::cout << "Attempted to unload instance, but no instance is active." << std::endl;
	}
}

Instance* Game::getActiveInstance()
{
	return _activeInstance;
}

Window* Game::getActiveWindow()
{
	return _activeWindow;
}

void Game::linkWindow(Window* window)
{
	glfwMakeContextCurrent(window->getGLWindow());	// Might move back to window
	_activeWindow = window;
}

int Game::getStatus()
{
	return _status;
}

Game::~Game()
{
	delete _tickHandler;
}