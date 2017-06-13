#pragma once
#include "..\game\Game.h"
#include <vector>

class Game;	// This is bad...

class TickHandler {

private:
	Game* _game;
	double _UPS;

public:
	TickHandler(Game&, double);
	void run();
};