#include "TickHandler.h"
#include <iostream>

TickHandler::TickHandler(Game& game, double UPS)
{
	_game = &game;
	_UPS = UPS;
}

void TickHandler::run()
{
	_game->initialize();
	_game->onStart();
	while (_game->getStatus())
	{
		if (glfwWindowShouldClose(_game->getActiveWindow()->getGLWindow())){
			_game->stop(); break;
		}

		// Update
		_game->onUpdate();

		// RENDER
		_game->getActiveWindow()->clear();
		_game->getActiveScene()->onRender();	// Swap with something better
		_game->getActiveWindow()->update();

		// INPUT
		_game->getInput()->update();
	}
}