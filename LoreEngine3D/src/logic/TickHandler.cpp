#include "TickHandler.h"
#include "../utils/Timer.h"
#include <iostream>

TickHandler::TickHandler(Game& game) : _game(&game) {}

void TickHandler::run()
{
	_game->initialize();
	_game->onStart();

	Timer msTimer;
	Timer frameTimer;
	float time = 0;
	unsigned int frames = 0;

	while (_game->getStatus())
	{
		if (glfwWindowShouldClose(_game->getActiveWindow()->getGLWindow())) {
			_game->stop(); break;
		}

		update();

		frames++;

		if (frameTimer.elapsed() - time > 1.0)
		{
			time += 1.0;
			printf(" %d FPS\n", frames);
			frames = 0;

			tick();
		}

		render();
	}

}

void TickHandler::tick()
{
	// Tick
	_game->getActiveScene()->onTick();
}

void TickHandler::update()
{
	// INPUT
	_game->getInput()->update();

	// Update
	_game->onUpdate();
	_game->getActiveScene()->onUpdate();	// MOVE TO GAME
}

void TickHandler::render()
{
	// RENDER
	_game->getActiveWindow()->clear();
	_game->getActiveScene()->onRender(); 	// MOVE TO GAME
	_game->getActiveWindow()->update();

}