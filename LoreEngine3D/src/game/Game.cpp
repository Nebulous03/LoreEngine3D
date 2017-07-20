#include "Game.h"
#include "..\graphics\Graphics.h"
#include <iostream>
#include "../utils/LoreInfo.h"
#include "../logic/Input.h"

Game::Game()
{
	_status		  = GAME_STOPPED;
	_activeWindow = nullptr;
	_graphics	  = nullptr;
	_tickHandler  = new TickHandler(*this);
	_activeScene  = nullptr;
	_input		  = nullptr;

	// Move ?
	std::cout << " ================================================================================================" << std::endl;
	std::cout << "  LORE GAME ENGINE " << std::endl;
	std::cout << "   Verson: " << LORE_VERSION << std::endl;
	std::cout << "   Author: " << LORE_AUTHOR << std::endl;
	std::cout << "   Copyright: " << LORE_COPYRIGHT << std::endl;
	std::cout << " ================================================================================================" << std::endl;

}

void Game::initialize()
{
	_input = new Input(*_activeWindow);
	_input->init();
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
	_activeScene->onLoad(*this);
}

void Game::unloadActiveInstance()
{
	if (_activeScene) {
		_activeScene->onUnload(*this);
		//delete _activeScene; // Maybe?
		_activeScene = nullptr;
	}
	else {
		std::cout << "Attempted to unload instance, but no instance is active." << std::endl;
	}
}

Graphics& Game::getGraphics()
{
	return *_graphics;
}

TickHandler& Game::getTickHandler()
{
	return *_tickHandler;
}

Scene& Game::getActiveScene()
{
	return *_activeScene;
}

Window& Game::getActiveWindow()
{
	return *_activeWindow;
}

Input& Game::getInput()
{
	return *_input;
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