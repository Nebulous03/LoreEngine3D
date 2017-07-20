#pragma once
#include "Game.h"

class Game;

class Scene {

public:
	virtual void onLoad(Game& game)					= 0;
	virtual void onUnload(Game& game)				= 0;
	virtual void onTick(Game& game, double delta)   = 0;
	virtual void onUpdate(Game& game, double delta)	= 0;
	virtual void onRender()							= 0;

};
