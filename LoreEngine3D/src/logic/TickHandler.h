#pragma once
#include "..\game\Game.h"
#include <vector>

#define MAX_UPS 60.0
#define MAX_FPS 60.0

class Game;	// This is bad...

class TickHandler {

private:
	Game* _game;
	double _UPS = MAX_UPS;
	double _FPS = MAX_FPS;
	bool _isCapped = false;

	void tick();
	void update();
	void render();

public:
	TickHandler(Game& game);
	void run();
};