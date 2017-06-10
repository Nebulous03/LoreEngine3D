#include "Game.h"
#include "..\graphics\Graphics.h"
#include <iostream>

Game::Game()
{
	_status		  = GAME_STOPPED;
	_activeWindow = nullptr;
	_graphics	  = nullptr;
	_tickHandler  = new TickHandler(*this, 60.0);
	_activeScene  = nullptr;
}

void Game::start()
{
	// Call other start functions here
	_status = GAME_RUNNING;	//Move to tickhandler
	_tickHandler->run();
}

void Game::stop()
{
	// Call other stop functions here
	_status = GAME_STOPPED;
	onStop();
	unloadActiveInstance();
	_activeWindow->destroyWindow();
	_graphics->terminateOpenGL();
}

void Game::loadScene(Scene* scene)
{
	// TODO: Check for active instance
	_activeScene = scene;
	_activeScene->onLoad();
}

void Game::unloadActiveInstance()
{
	if (_activeScene) {
		_activeScene->onUnload();
		//delete _activeScene; // Maybe?
		_activeScene = nullptr;
	}
	else {
		std::cout << "Attempted to unload instance, but no instance is active." << std::endl;
	}
}

Graphics* Game::getGraphics()
{
	return _graphics;
}

Scene* Game::getActiveScene()
{
	return _activeScene;
}

Window* Game::getActiveWindow()
{
	return _activeWindow;
}

void Game::linkWindow(Window* window)
{
	_graphics = window->getGraphics();
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