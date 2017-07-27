#include "TickHandler.h"
#include "../utils/Timer.h"
#include <iostream>

TickHandler::TickHandler(Game& game) : _game(&game) {}

void TickHandler::run()
{
	_game->initialize();
	_game->onStart();

	double oldTime = 0.0;
	double currentTime = 0.0;

	while (_game->getStatus())
	{
		if (glfwWindowShouldClose(_game->getActiveWindow().getGLWindow())) {
			_game->stop(); break;
		}

		oldTime = currentTime;
		currentTime = _updateTimer.elapsed();
		_updateDelta = currentTime - oldTime;

		if (_frameTimer.elapsed() - _frameTime > 1.0)
		{
			_frameTime += 1.0;
			_activeFPS = _frames;
			_frames = 0;
		}

		if (_isTPSCapped && _updateTimer.elapsed() - _updateTime > 1.0 / _TPS) {
			_updateTime += 1.0 / _TPS;
			tick(_updateDelta);
		}

		update(_updateDelta);

		_msTimer.reset();
		render();
		_msTime = _msTimer.elapsed();

		_frames++;
	}

}

void TickHandler::tick(double delta)
{
	// Tick
	_game->getActiveScene().onTick(*_game, delta);
}

void TickHandler::update(double delta)
{
	// Update
	_game->onUpdate();
	_game->getActiveScene().onUpdate(*_game, delta);	// MOVE TO GAME
}

void TickHandler::render()
{
	// RENDER
	_game->getActiveWindow().clear();
	_game->getActiveScene().onRender(); 	// MOVE TO GAME
	_game->getActiveWindow().update();

}

void TickHandler::setTPSLimit(double tps)
{
	_TPS = tps;
}

void TickHandler::setFPSLimit(double fps)
{
	_FPS = fps;
}

unsigned int TickHandler::getFPS() const
{
	return _activeFPS;
}

double TickHandler::getRenderTime() const
{
	return _msTime;
}