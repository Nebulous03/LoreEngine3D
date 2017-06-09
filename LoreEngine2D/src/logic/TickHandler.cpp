#include "TickHandler.h"
#include <iostream>

double TickHandler::_UPS = 60.0;
Game* TickHandler::_game = nullptr;
std::vector<Tickable*> TickHandler::_tickables;
std::vector<Updateable*> TickHandler::_updatables;
std::vector<FastUpdateable*> TickHandler::_fastUpdatables;

TickHandler::TickHandler(Game& game, double UPS)
{
	_game = &game;
	_UPS = UPS;
}

void TickHandler::registerTickEvent(Tickable* tickable)
{
	_tickables.push_back(tickable);
}
void TickHandler::registerUpdateEvent(Updateable* updatable)
{
	_updatables.push_back(updatable);
}
void TickHandler::registerFastUpdateEvent(FastUpdateable* fastUpdatable)
{
	_fastUpdatables.push_back(fastUpdatable);
}

void TickHandler::run()
{
	Window* window = _game->getActiveWindow();
	while (_game->getStatus())
	{
		if (glfwWindowShouldClose(window->getGLWindow())) {
			std::cout << _game << std::endl;
			_game->stop();
			break;
		}

		_game->onTick();
		window->updateWindow();

		// Keep running
		glfwPollEvents();
	}
}