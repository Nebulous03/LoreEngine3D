#pragma once
#include "game\Game.h"

class TestGame : public Game
{

public:
	void onStart();
	void onStop();
	void onTick();
	void onUpdate();

};