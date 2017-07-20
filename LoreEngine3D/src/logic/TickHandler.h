#pragma once
#include "..\game\Game.h"
#include "..\utils\Timer.h"
#include <vector>

#define MAX_TPS 10.0
#define MAX_FPS 60.0

class Game;	// This is bad...

class TickHandler {

private:

	Game* _game;
	double _TPS = MAX_TPS;
	double _FPS = MAX_FPS;
	bool _isTPSCapped = true;
	bool _isFPSCapped = false;
	unsigned int _activeFPS = 0;

	Timer _msTimer;
	Timer _frameTimer;
	Timer _updateTimer;
	double _frameTime = 0.0;
	double _updateTime = 0.0;
	double _msTime = 0.0;
	unsigned int _frames = 0;

	double _updateDelta = 0.0;

	void tick(double delta);
	void update(double delta);
	void render();

public:
	TickHandler(Game& game);
	void run();
	void setTPSLimit(double tps);
	void setFPSLimit(double fps);
	unsigned int getFPS() const;
	double getRenderTime() const;
};